#include <algorithm>
#include "MysteryDungeonMaker.h"
#include "RandExtended.h"
#include "Vector2.h"
#include "ReducedMap.h"
#include "Section.h"
#include "Rect.h"
#include "Component.h"

MysteryDungeonMaker::MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight)
	:mapWidth(mapWidth),
	mapHeight(mapHeight),
	sectionWidth(sectionWidth),
	sectionHeight(sectionHeight)
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
	std::vector<Vector2> sectionCoordinate;
	for (size_t i = 0; i < mapHeight; i++)
	{
		for (size_t j = 0; j < mapWidth; j++)
		{
			sectionCoordinate.push_back(Vector2(j, i));
			section[i][j].SetComponent(i, j);
		}
	}
	std::random_shuffle(sectionCoordinate.begin(), sectionCoordinate.end());
	for (size_t i = 0; i < roomNum; i++)
	{
		int i_section = sectionCoordinate[i].y;
		int j_section = sectionCoordinate[i].x;
		section[i_section][j_section].PutRoomMark();

		Component startPoint;
		startPoint.i = sectionHeight * i_section;
		startPoint.j = sectionWidth * j_section;
		int width = GetRandInRange(4, sectionWidth - 2);
		int height = GetRandInRange(4, sectionHeight - 2);
		MakeRoom(startPoint, width, height);
	}
	MakePath();
	return map;
}

void MysteryDungeonMaker::MakeRoom(Component const& startPoint, int roomWidth, int roomHeight)
{
	Rect temp;//部屋の始点設置可能領域
	temp.x1 = startPoint.j + 1;
	temp.y1 = startPoint.i + 1;
	temp.x2 = startPoint.j + sectionWidth - 1 - roomWidth;
	temp.y2 = startPoint.i + sectionHeight - 1 - roomHeight;

	Rect room;//実際に配置される部屋
	room.x1 = GetRandInRange(temp.x1, temp.x2);
	room.y1 = GetRandInRange(temp.y1, temp.y2);
	room.x2 = room.x1 + roomWidth;
	room.y2 = room.y1 + roomHeight;

	section[startPoint.i/sectionHeight][startPoint.j/sectionWidth].SetRoom(room);

	for (int i = 0; i < roomHeight; ++i)
	{
		for (int j = 0; j < roomWidth; ++j)
		{
			map[room.y1 + i][room.x1 + j] = 1;
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
			Section sec = section[i][j];
			Rect room = sec.GetRoom();
			if (sec.HasRoom())
			{
				Vector2 v;
				if(i - 1>= 0)
				{
					v.x = GetRandInRange(room.x1, room.x2 - 1);
					v.y = room.y1-1;
					int diff = room.y1 - i*sectionHeight;
					for (int k = 0; k < diff; k++)
					{
						map[v.y-k][v.x] = MapObject::PATH;
					}
				}
			}
		}
	}
}


Vector2 MysteryDungeonMaker::ConvertToSectionCoord(const Vector2& mapCoord)
{
	Vector2 v;
	v.x = mapCoord.x / sectionWidth;
	v.y = mapCoord.y / sectionHeight;
	return v;
}
