#include <cmath>
#include <algorithm>
#include "MysteryDungeonMaker.h"
#include "RandExtended.h"
#include "Vector2.h"
#include "ReducedMap.h"
#include "Section.h"
#include "Rect.h"
#include "Component.h"

const int up_down[] = { -1, 0, 1, 0 };
const int right_left[] = { 0, 1, 0, -1 };

MysteryDungeonMaker::MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight)
	:mapWidth(mapWidth),
	mapHeight(mapHeight),
	sectionWidth(sectionWidth),
	sectionHeight(sectionHeight),
	minRoomWidth(4),
	minRoomHeight(4)
{
	NewMap();
	ResetMap();
}


MysteryDungeonMaker::~MysteryDungeonMaker()
{
	DeleteMap();
}

void MysteryDungeonMaker::NewMap()
{
	map = new int*[sectionHeight*mapHeight];
	for (size_t i = 0; i < sectionHeight*mapHeight; i++)
	{
		map[i] = new int[sectionWidth*mapWidth];
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
}

int** MysteryDungeonMaker::CreateDungeon()
{
	int sectionNum = mapWidth*mapHeight;
	const int roomNum = GetRandInRange(sectionNum / 3, sectionNum / 2);
	std::vector<Component> sections;
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			sections.push_back(Component(i, j));
			section[i][j].SetComponent(i, j);
		}
	}

	std::random_shuffle(sections.begin(), sections.end());

	for (int i = 0; i < roomNum; i++)
	{
		int i_section = sections[i].i;
		int j_section = sections[i].j;
		section[i_section][j_section].PutRoomMark();
		
		Component startPoint(sectionHeight * i_section, sectionWidth * j_section);
		int width = GetRandInRange(minRoomWidth, sectionWidth - 4);
		int height = GetRandInRange(minRoomHeight, sectionHeight - 4);
		MakeRoom(startPoint, width, height);
	}
	MakePath();
	return map;
}

void MysteryDungeonMaker::MakeRoom(Component const& startPoint, int roomWidth, int roomHeight)
{
	Rect temp;//部屋の始点設置可能領域
	temp.x1 = startPoint.j + 2;
	temp.y1 = startPoint.i + 2;
	temp.x2 = startPoint.j + sectionWidth - 2 - roomWidth;
	temp.y2 = startPoint.i + sectionHeight - 2 - roomHeight;

	Rect room;//実際に配置される部屋
	room.x1 = GetRandInRange(temp.x1, temp.x2);
	room.y1 = GetRandInRange(temp.y1, temp.y2);
	room.x2 = room.x1 + roomWidth-1;
	room.y2 = room.y1 + roomHeight-1;

	section[startPoint.i/sectionHeight][startPoint.j/sectionWidth].SetRoom(room);

	for (int i = 0; i < roomHeight; ++i)
	{
		for (int j = 0; j < roomWidth; ++j)
		{
			map[room.y1 + i][room.x1 + j] = FLOOR;
		}
	}
}

void MysteryDungeonMaker::ResetMap()
{
	for (size_t i = 0; i < sectionHeight*mapHeight; i++)
	{
		for (size_t j = 0; j < sectionWidth*mapWidth; j++)
		{
			map[i][j] = 0;
		}
	}
}


void MysteryDungeonMaker::MakePath()
{
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
							section[i_rota][j_rota].SetRoomConnected(&section[i_rota][j_rota]);
							ConnectAdjacentRoom(section[i][j], section[i_rota][j_rota]);
						}
					}
				}

				//Component component;
				//if(i - 1>= 0)
				//{
				//	component.j = GetRandInRange(room.x1, room.x2 - 1);
				//	component.i = room.y1-1;
				//	int diff = room.y1 - i*sectionHeight;
				//	for (int k = 0; k < diff; k++)
				//	{
				//		map[component.i-k][component.j] = MapObject::PATH;
				//	}
				//}
			}
		}
	}
}

void MysteryDungeonMaker::ConnectAdjacentRoom(Section const& center, Section const& around)
{
	Component comp_center = center.GetComponent();
	Component comp_around = around.GetComponent();
	Rect room_center = center.GetRoom();
	Rect room_around = around.GetRoom();
	Component start(0,0);
	Component goal(0,0);

	int door;
	if (comp_center.i == comp_around.i)
	{
		if (comp_center.j > comp_around.j)
		{
			Component comp_temp = comp_center;
			comp_center = comp_around;
			comp_around = comp_temp;

			Rect room_temp = room_center;
			room_center = room_around;
			room_around = room_temp;
		}
		if ()
		{
			door = GetRandInRange(room_center.y1, room_center.y2);
			for (int j = room_center.x2 + 1; j <= (comp_center.j + 1)*sectionWidth; j++)
			{
				map[door][j] = PATH;
			}
			door = GetRandInRange(room_around.y1, room_around.y2);
			for (int j = room_around.x1 - 1; j >= (comp_center.j + 1)*sectionWidth + 1; j--)
			{
				map[door][j] = PATH;
			}
		}

	}
	else
	{
	}

	//switch (to)
	//{
	//case UP: 
	//	int door;
	//	door = GetRandInRange(room1.x1, room1.x2);
	//	int i_path1 = room1.y1;
	//	map[--i_path1][door] = PATH;
	//	map[--i_path1][door] = PATH;
	//	start.i = i_path1;
	//	start.j = door;
	//	door = GetRandInRange(room_around.x1, room_around.x2);
	//	int i_path2 = room_around.y2;
	//	map[++i_path2][door] = PATH;
	//	map[++i_path2][door] = PATH;
	//	goal.i = i_path2;
	//	goal.j = door;
	//	break;
	//case RIGHT: break;
	//case DOWN: break;
	//case LEFT: break;
	//default: break;
	//}

	//int i_initial = start.i;
	//int distance = abs(i_initial - goal.i);
	//int sign = (goal.i-start.i) / distance;
	//for (; start.i < i_initial+sign*distance; start.i += sign)
	//{
	//	map[start.i][start.j] = PATH;
	//}
	//for (; start.i != goal.i; start.i += sign)
	//{
	//	map[start.i][start.j] = PATH;
	//}

	//int j;
	//for (j = fmin(start.j, goal.j); j < fmax(start.j, goal.j); ++j)
	//{
	//	map[start.i][j] = PATH;
	//}


	if (start.i == goal.i)
	{

	}
	else if (start.j == goal.j)
	{

	}
	int i_larger = fmax(start.i, goal.i);
	int j_larger = fmax(start.j, goal.j);
}