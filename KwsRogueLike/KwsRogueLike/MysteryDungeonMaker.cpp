#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
#include <random>
#include "MysteryDungeonMaker.h"
#include "RandExtended.h"
#include "Vector2.h"
#include "ReducedMap.h"
#include "Section.h"
#include "Rect.h"
#include "Component.h"
#include "SectionUtil.h"
#include "DungeonMakerHelper.h"

const int up_down[] = { -1, 0, 1, 0 };
const int right_left[] = { 0, 1, 0, -1 };

MysteryDungeonMaker::MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight)
	:mapWidth(mapWidth),
	mapHeight(mapHeight),
	sectionWidth(sectionWidth),
	sectionHeight(sectionHeight),
	minRoomWidth(4),
	minRoomHeight(4),
	roomNum(0)
{
	int sectionNum = mapWidth*mapHeight;
	this->roomNum = GetRandInRange(sectionNum / 3, sectionNum / 2);
}

MysteryDungeonMaker::~MysteryDungeonMaker()
{
}

void MysteryDungeonMaker::NewMap()
{
	map = new MapComponent*[sectionHeight*mapHeight];
	for (size_t i = 0; i < sectionHeight*mapHeight; i++)
	{
		map[i] = new MapComponent[sectionWidth*mapWidth];
	}

	section = new Section*[mapHeight];
	for (int i = 0; i < mapWidth; i++)
	{
		section[i] = new Section[mapWidth];
	}
}

void MysteryDungeonMaker::DeleteMap()
{
	for (size_t i = 0; i < sectionHeight*mapHeight; i++)
	{
		delete[] map[i];
	}
	delete[] map;

	map = nullptr;
}

void MysteryDungeonMaker::ResetMap()
{
	for (size_t i = 0; i < sectionHeight*mapHeight; i++)
	{
		for (size_t j = 0; j < sectionWidth*mapWidth; j++)
		{
			map[i][j] = WALL;
		}
	}
}

void MysteryDungeonMaker::ResetGroupId()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			section[i][j].ResetGroupId();
		}
	}
}

std::vector<std::vector<MysteryDungeonMaker::MapComponent>> MysteryDungeonMaker::CreateDungeon()
{
	NewMap();
	ResetMap();

	std::vector<std::vector<MapComponent>> tempMap;

	std::vector<Component> sections;
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			sections.push_back(Component(i, j));
			section[i][j].SetComponent(i, j);
		}
	}

	std::random_device rd;
	shuffle(sections.begin(), sections.end(), std::mt19937_64(rd()));

	for (int i = 0; i < roomNum; i++)
	{
		int i_section = sections[i].i;
		int j_section = sections[i].j;

		int width = GetRandInRange(minRoomWidth, sectionWidth - 4);
		int height = GetRandInRange(minRoomHeight, sectionHeight - 4);
		MakeRoom(Component(i_section, j_section), width, height);
	}
	MakePath();

	for (int i = 0; i < sectionHeight*mapHeight; i++)
	{
		tempMap.push_back(std::vector<MapComponent>());
		for (int j = 0; j < sectionWidth*mapWidth; j++)
		{
			tempMap[i].push_back(map[i][j]);
		}
	}

	DeleteMap();

	return tempMap;
}

void MysteryDungeonMaker::SetRoomNum(int roomNum)
{
	if (roomNum <= mapHeight*mapWidth)
		this->roomNum = roomNum;
}

void MysteryDungeonMaker::MakeRoom(Component const& section, int roomWidth, int roomHeight)
{
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

	this->section[sectionStartPoint.i/sectionHeight][sectionStartPoint.j/sectionWidth].SetRoom(room);

	for (int i = 0; i < roomHeight; ++i)
		for (int j = 0; j < roomWidth; ++j)
			map[room.y1 + i][room.x1 + j] = FLOOR;
}

void MysteryDungeonMaker::MakePath()
{
	//ステップ1(部屋のあるセクションの上下左右をチェック)
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (section[i][j].HasRoom())
			{
				for (int k = 0; k < 4; ++k)
				{
					int i_rota=i+up_down[k];
					int j_rota=j+right_left[k];
					if ((0 <= i_rota && i_rota < mapHeight) && (0 <= j_rota && j_rota < mapWidth))
					{
						if (section[i_rota][j_rota].HasRoom())
						{
							ConnectAdjacentRoom(&section[i][j], &section[i_rota][j_rota]);
						}
					}
				}
			}
		}
	}

	//ステップ2(部屋のないセクションの上下左右をチェック)
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if ( ! section[i][j].HasRoom())
			{
				std::vector<Section*> aroundSections;
				for (int k = 0; k < 4; ++k)
				{
					int i_rota = i + up_down[k];
					int j_rota = j + right_left[k];
					if ((0 <= i_rota && i_rota < mapHeight) && (0 <= j_rota && j_rota < mapWidth))
					{
						if (section[i_rota][j_rota].HasRoom())
							aroundSections.push_back(&section[i_rota][j_rota]);
					}
				}

				if (aroundSections.size() == 2)
				{
					if( ! aroundSections[0]->isConnectedTo(*aroundSections[1]))
					{
						MakeRoom(Component(i, j), 1, 1);
						ConnectAdjacentRoom(&section[i][j], aroundSections[0]);
						ConnectAdjacentRoom(&section[i][j], aroundSections[1]);
						RemoveRoom(section[i][j].GetRoom());
						section[i][j].SetHasPath(true);
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

				Section* sectionMadeRoom = &section[route[i + 1].i][route[i + 1].j];
				ConnectAdjacentRoom(&section[route[i].i][route[i].j], sectionMadeRoom);
			}

			for (int i = 1; i < route.size() - 1; i++)
			{
				Section* roomRemoved = &section[route[i].i][route[i].j];
				RemoveRoom(roomRemoved->GetRoom());
				roomRemoved->SetHasPath(true);
			}
		}

		ResetGroupId();
		groups = ClassifyGroups();
	}
}

void MysteryDungeonMaker::ConnectAdjacentRoom(Section *center, Section *around)
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
			int j_border = (sectionComp_center.j + 1)*sectionWidth - 1;

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
				map[door_center][j] = PATH;
			}

			for (int j = room_around.x1 - 1; j > j_border; j--)
			{
				map[door_around][j] = PATH;
			}

			for (int i = fmin(door_center, door_around); i <= fmax(door_center, door_around); i++)
			{
				map[i][j_border] = PATH;
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
				map[i][door_center] = PATH;
			}
			for (int i = room_around.y1 - 1; i > i_border; i--)
			{
				map[i][door_around] = PATH;
			}

			for (int j = fmin(door_center, door_around); j <= fmax(door_center, door_around); j++)
			{
				map[i_border][j] = PATH;
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
			map[i][j] = PATH;
		}
	}
	section[room.y1 / sectionHeight][room.x1 / sectionWidth].RemoveRoom();
}

std::vector<std::vector<Section*>> MysteryDungeonMaker::ClassifyGroups()
{
	std::vector<std::vector<Section*>> groups;
	int groupId = 0;

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			Section* current = &section[i][j];
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

	while (!queue.empty() && !isGoaled)
	{
		current = queue.front();
		queue.pop();

		for (int k = 0; k < 4; k++)
		{
			int i = current->GetComponent().i + up_down[k];
			int j = current->GetComponent().j + right_left[k];
			if ((0 <= i && i < mapHeight) && (0 <= j && j < mapWidth))
			{
				Section* next = &section[i][j];
				if (next->HasRoom() && next->GetGroupId() != start.GetGroupId())
				{
					goal = next;
					isGoaled = true;
					routeMap.insert(std::make_pair(next->GetComponent(), current->GetComponent()));
					break;
				}

				if (find(visited.begin(), visited.end(), next->GetComponent()) == visited.end() 
					&& !section[i][j].HasPath()
					&& !section[i][j].HasRoom())
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