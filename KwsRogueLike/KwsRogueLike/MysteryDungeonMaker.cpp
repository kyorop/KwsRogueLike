#include <algorithm>
#include <utility>
#include <queue>
#include <map>
#include "MysteryDungeonMaker.h"
#include "RandExtended.h"
#include "Section.h"
#include "Rect.h"
#include "SectionUtil.h"
#include "DungeonMakerHelper.h"
#include "DungeonData.h"
#include "DungeonSize.h"
#include <random>
#include "generalconstant.h"
#include "RoomData.h"
#include "BlockRect.h"
#include "Component.h"

const int up_down[] = { -1, 0, 1, 0 };
const int right_left[] = { 0, 1, 0, -1 };


MysteryDungeonMaker::MysteryDungeonMaker(const DungeonSize& dungeonSize)
	:dungeonSize(std::make_unique<DungeonSize>(dungeonSize)),
	map(dungeonSize.DungeonHeight(), std::vector<ObjTypeOnMap>(dungeonSize.DungeonWidth())),
	sections(dungeonSize.DungeonRowNum(), std::vector<Section>(dungeonSize.DungeonColumnNum()))
{
	size_t sectionNum = dungeonSize.AllSectionNum();
	roomNum = GetRandInRange(sectionNum / 3, sectionNum / 2);
}

MysteryDungeonMaker::~MysteryDungeonMaker()
{
}

void MysteryDungeonMaker::Initialize()
{
	CreateMap();
}

DungeonData MysteryDungeonMaker::DungeonData()
{
	::DungeonData dData(dungeonSize->DungeonHeight(), dungeonSize->DungeonWidth());

	const size_t rowNum = dungeonSize->DungeonHeight();
	const size_t columnNum = dungeonSize->DungeonWidth();
	for (size_t i = 0; i < rowNum; i++)
	{
		for (size_t j = 0; j < columnNum; j++)
		{
			dData.AddType(Component(i, j), map[i][j]);
		}
	}

	return dData;
}

RoomDataStores MysteryDungeonMaker::RoomData()
{
	RoomDataStores roomData;
	for (size_t i = 0; i < dungeonSize->DungeonRowNum(); i++)
	{
		for (size_t j = 0; j < dungeonSize->DungeonColumnNum(); j++)
		{
			if (sections[i][j].HasRoom())
			{
				auto rect = sections[i][j].GetRoom();
				BlockRect blockRect(rect.x1, rect.y1, rect.x2, rect.y2);
				roomData.Add(blockRect);
			}
		}
	}

	return roomData;
}

void MysteryDungeonMaker::ResetMap()
{
	const size_t rowNum = dungeonSize->DungeonHeight();
	const size_t columnNum = dungeonSize->DungeonWidth();
	for (size_t i = 0; i < rowNum; i++)
	{
		for (size_t j = 0; j < columnNum; j++)
		{
			map[i][j] = ObjTypeOnMap::WALL;
		}
	}
}

void MysteryDungeonMaker::ResetGroupId()
{
	const size_t sectionRowNum = dungeonSize->DungeonRowNum();
	const size_t sectionColumnNum = dungeonSize->DungeonColumnNum();
	for (size_t i = 0; i < sectionRowNum; i++)
	{
		for (size_t j = 0; j < sectionColumnNum; j++)
		{
			sections[i][j].ResetGroupId();
		}
	}
}

void MysteryDungeonMaker::CreateMap()
{
	ResetMap();

	std::vector<Component> section_components;
	const size_t sectionRowNum = dungeonSize->DungeonRowNum();
	const size_t sectionColumnNum = dungeonSize->DungeonColumnNum();
	for (size_t i = 0; i < sectionRowNum; i++)
	{
		for (size_t j = 0; j < sectionColumnNum; j++)
		{
			section_components.push_back(Component(i, j));
			this->sections[i][j].SetComponent(i, j);
		}
	}

	std::random_device rd;
	shuffle(section_components.begin(), section_components.end(), std::mt19937_64(rd()));

	for (int i = 0; i < roomNum; i++)
	{
		int i_section = section_components[i].i;
		int j_section = section_components[i].j;

		int width = GetRandInRange(minRoomWidth, sectionColumnNum - 4);
		int height = GetRandInRange(minRoomHeight, sectionRowNum - 4);
		MakeRoom(Component(i_section, j_section), width, height);
	}
	MakePath();
}

void MysteryDungeonMaker::SetRoomNum(int roomNum)
{
	if (roomNum <= dungeonSize->AllSectionNum())
		this->roomNum = roomNum;
}

void MysteryDungeonMaker::MakeRoom(Component const& section, int roomWidth, int roomHeight)
{
	const size_t sectionHeight = dungeonSize->SectionHeight();
	const size_t sectionWidth = dungeonSize->SectionWidth();
	Component sectionStartPoint(section.i*sectionHeight, section.j*sectionWidth);
	Rect temp;//部屋の始点設置可能領域
	temp.x1 = sectionStartPoint.j + 2;
	temp.y1 = sectionStartPoint.i + 2;
	temp.x2 = sectionStartPoint.j + sectionWidth - 2 - roomWidth;
	temp.y2 = sectionStartPoint.i + sectionHeight - 2 - roomHeight;

	Rect room;//実際に配置される部屋
	room.x1 = GetRandInRange(temp.x1, temp.x2);
	room.y1 = GetRandInRange(temp.y1, temp.y2);
	room.x2 = room.x1 + roomWidth-1;
	room.y2 = room.y1 + roomHeight-1;

	this->sections[sectionStartPoint.i / sectionHeight][sectionStartPoint.j / sectionWidth].SetRoom(room);

	for (int i = 0; i < roomHeight; ++i)
		for (int j = 0; j < roomWidth; ++j)
			map[room.y1 + i][room.x1 + j] = ObjTypeOnMap::FLOOR;
}

void MysteryDungeonMaker::MakePath()
{
	//ステップ1(部屋のあるセクションの上下左右をチェック)
	int sectionRowNum=dungeonSize->DungeonRowNum();
	int sectionColumnNum=dungeonSize->DungeonColumnNum();
	for (int i = 0; i < sectionRowNum; i++)
	{
		for (int j = 0; j < sectionColumnNum; j++)
		{
			if (sections[i][j].HasRoom())
			{
				for (int k = 0; k < 4; ++k)
				{
					int i_rota=i+up_down[k];
					int j_rota=j+right_left[k];
					if ((0 <= i_rota && i_rota < sectionRowNum) && (0 <= j_rota && j_rota < sectionColumnNum))
					{
						if (sections[i_rota][j_rota].HasRoom())
						{
							ConnectAdjacentRoom(&sections[i][j], &sections[i_rota][j_rota]);
						}
					}
				}
			}
		}
	}

	//ステップ2(部屋のないセクションの上下左右をチェック)
	for (int i = 0; i < sectionRowNum; i++)
	{
		for (int j = 0; j < sectionColumnNum; j++)
		{
			if ( ! sections[i][j].HasRoom())
			{
				std::vector<Section*> aroundSections;
				for (int k = 0; k < 4; ++k)
				{
					int i_rota = i + up_down[k];
					int j_rota = j + right_left[k];
					if ((0 <= i_rota && i_rota < sectionRowNum) && (0 <= j_rota && j_rota < sectionColumnNum))
					{
						if (sections[i_rota][j_rota].HasRoom())
							aroundSections.push_back(&sections[i_rota][j_rota]);
					}
				}

				if (aroundSections.size() == 2)
				{
					if( ! aroundSections[0]->isConnectedTo(*aroundSections[1]))
					{
						MakeRoom(Component(i, j), 1, 1);
						ConnectAdjacentRoom(&sections[i][j], aroundSections[0]);
						ConnectAdjacentRoom(&sections[i][j], aroundSections[1]);
						RemoveRoom(sections[i][j].GetRoom());
						sections[i][j].SetHasPath(true);
					}
				}
			}
		}
	}

	//ステップ3
	std::vector<std::vector<Section*>> groups = ClassifyGroups();
	std::vector<Component>route;
	while (groups.size() > 1)
	{
		DungeonMakerHelper::SortByGroupSize(&groups);
		for (int i = 0; i < groups[0].size(); i++)
		{
			route = SearchShortestRoute(*groups[0][i]);
			if ( ! route.empty())
				break;
		}
		
		if (!route.empty())
		{
			Component goal = route[route.size() - 1];
			for (int i = 0; i < route.size() - 1; i++)
			{
				if (route[i+1] != goal)
					MakeRoom(route[i + 1], 1, 1);

				Section* sectionMadeRoom = &sections[route[i + 1].i][route[i + 1].j];
				ConnectAdjacentRoom(&sections[route[i].i][route[i].j], sectionMadeRoom);
			}

			for (int i = 1; i < route.size() - 1; i++)
			{
				Section* roomRemoved = &sections[route[i].i][route[i].j];
				RemoveRoom(roomRemoved->GetRoom());
				roomRemoved->SetHasPath(true);
			}
		}

		ResetGroupId();
		groups = ClassifyGroups();
	}
}

void MysteryDungeonMaker::ConnectAdjacentRoom(Section* center, Section* around)
{
	Component sectionComp_center = center->GetComponent();
	Component sectionComp_around = around->GetComponent();
	Rect room_center = center->GetRoom();
	Rect room_around = around->GetRoom();

	int door_center;
	int door_around;
	if (!center->isConnectedTo(*around))
	{
		if (sectionComp_center.i == sectionComp_around.i)//部屋が横並びの時
		{
			if (sectionComp_center.j > sectionComp_around.j)
			{
				sectionComp_center = sectionComp_around;

				Rect room_temp = room_center;
				room_center = room_around;
				room_around = room_temp;
			}
			int j_border = (sectionComp_center.j + 1)* GeneralConstant::sectionWidth - 1;

			if (room_center.y2-room_center.y1 == 0)
			{
				door_center = GetRandInRange(room_center.y1, room_center.y2);
			}
			else
			{
				door_center = GetRandInRange(room_center.y1 + 1, room_center.y2 - 1);
			}

			if (room_around.y2 - room_around.y1 == 0)
			{
				door_around = GetRandInRange(room_around.y1, room_around.y2);
			}
			else
			{
				door_around = GetRandInRange(room_around.y1 + 1, room_around.y2 - 1);
			}

			for (int j = room_center.x2 + 1; j <= j_border; j++)
			{
				map[door_center][j] = ObjTypeOnMap::PATH;
			}

			for (int j = room_around.x1 - 1; j > j_border; j--)
			{
				map[door_around][j] = ObjTypeOnMap::PATH;
			}

			for (int i = std::min(door_center, door_around); i <= std::max(door_center, door_around); i++)
			{
				map[i][j_border] = ObjTypeOnMap::PATH;
			}
		}
		else//部屋が縦並びの時
		{
			if (sectionComp_center.i > sectionComp_around.i)
			{
				sectionComp_center = sectionComp_around;

				Rect room_temp = room_center;
				room_center = room_around;
				room_around = room_temp;
			}

			const size_t sectionHeight = dungeonSize->SectionHeight();
			int i_border = sectionComp_center.i*sectionHeight + sectionHeight - 1;
			
			if (room_center.x2 - room_center.x1 == 0)
			{
				door_center = GetRandInRange(room_center.x1, room_center.x2);
			}
			else
			{
				door_center = GetRandInRange(room_center.x1+1, room_center.x2-1);
			}

			if (room_around.x2 - room_around.x1 == 0)
			{
				door_around = GetRandInRange(room_around.x1, room_around.x2);
			}
			else
			{
				door_around = GetRandInRange(room_around.x1+1, room_around.x2-1);
			}
			
			for (int i = room_center.y2 + 1; i <= i_border;i++)
			{
				map[i][door_center] = ObjTypeOnMap::PATH;
			}
			for (int i = room_around.y1 - 1; i > i_border; i--)
			{
				map[i][door_around] = ObjTypeOnMap::PATH;
			}

			for (int j = std::min(door_center, door_around); j <= std::max(door_center, door_around); j++)
			{
				map[i_border][j] = ObjTypeOnMap::PATH;
			}
		}

		SectionUtil::ConnectToEachOther(center, around);
	}
}

void MysteryDungeonMaker::RemoveRoom(const Rect& room)
{
	for (int i = room.y1; i <= room.y2; i++)
	{
		for (int j = room.x1; j <= room.x2; j++)
		{
			map[i][j] = ObjTypeOnMap::PATH;
		}
	}
	const size_t sectionHeight = dungeonSize->SectionHeight();
	const size_t sectionWidth = dungeonSize->SectionWidth();
	sections[room.y1 / sectionHeight][room.x1 / sectionWidth].RemoveRoom();
}

std::vector<std::vector<Section*>> MysteryDungeonMaker::ClassifyGroups()
{
	std::vector<std::vector<Section*>> groups;
	int groupId = 0;

	int mapHeight=dungeonSize->DungeonRowNum();
	int sectionColumnNum = dungeonSize->DungeonColumnNum();
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < sectionColumnNum; j++)
		{
			Section* current = &sections[i][j];
			if (current->HasRoom())
			{
				if (groups.empty())
				{
					groups.push_back(current->SetGroupId(groupId++));
				}
				else
				{
					int  notMarked = 0;
					for (int i_groups = 0; i_groups < groups.size(); i_groups++)
					{
						if (!DungeonMakerHelper::HasComponent(groups[i_groups], current->GetComponent()))
						{
							notMarked++;
						}
					}
					if (notMarked == groups.size())
						groups.push_back(current->SetGroupId(groupId++));
				}
			}
		}
	}

	return groups;
}

std::vector<Component> MysteryDungeonMaker::SearchShortestRoute(const Section& start)
{
	std::queue<const Section*> queue;
	std::vector <Component> visited;
	std::map<Component, Component> routeMap;//<key,back>
	const Section* current;
	const Section* goal = nullptr;
	bool isGoaled = false;

	queue.push(&start);
	visited.push_back(start.GetComponent());

	int mapHeight=dungeonSize->DungeonRowNum();
	int sectionColumnNum = dungeonSize->DungeonColumnNum();
	while (!queue.empty() && !isGoaled)
	{
		current = queue.front();
		queue.pop();

		for (int k = 0; k < 4; k++)
		{
			int i = current->GetComponent().i + up_down[k];
			int j = current->GetComponent().j + right_left[k];
			if ((0 <= i && i < mapHeight) && (0 <= j && j < sectionColumnNum))
			{
				Section* next = &sections[i][j];
				if (next->HasRoom() && next->GetGroupId() != start.GetGroupId())
				{
					goal = next;
					isGoaled = true;
					routeMap.insert(std::make_pair(next->GetComponent(), current->GetComponent()));
					break;
				}

				if (find(visited.begin(), visited.end(), next->GetComponent()) == visited.end() 
					&& !sections[i][j].HasPath()
					&& !sections[i][j].HasRoom())
				{
					queue.push(next);
					routeMap.insert(std::make_pair(next->GetComponent(), current->GetComponent()));
				}

				visited.push_back(next->GetComponent());
			}
		}
	}

	std::vector<Component> route;

	if (isGoaled)
	{
		Component back;
		back = goal->GetComponent();
		route.push_back(goal->GetComponent());
		while (back != start.GetComponent())
		{
			back = routeMap.find(back)->second;
			route.push_back(back);
		}
	}

	reverse(route.begin(), route.end());
	return route;
}