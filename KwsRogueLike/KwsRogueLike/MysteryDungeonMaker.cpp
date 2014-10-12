#include <algorithm>
#include "MysteryDungeonMaker.h"
#include "RandExtended.h"
#include "Vector2.h"
#include "ReducedMap.h"

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

	rmap = new ReducedMap*[mapHeight];
	for (size_t i = 0; i < mapHeight; i++)
	{
		rmap[i] = new ReducedMap[mapWidth];
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
		}
	}
	std::random_shuffle(sectionCoordinate.begin(), sectionCoordinate.end());
	for (size_t i = 0; i < roomNum; i++)
	{
		int i_rmap = sectionCoordinate[i].y;
		int j_rmap = sectionCoordinate[i].x;

		Vector2 putRoomCoord;
		putRoomCoord.x = sectionWidth * j_rmap;
		putRoomCoord.y = sectionHeight * i_rmap;
		rmap[i_rmap][j_rmap].isRoom = true;

		Vector2 roomSize;
		roomSize.x = GetRandInRange(4, sectionWidth-2);
		roomSize.y = GetRandInRange(4, sectionHeight-2);
		MakeRoom(&putRoomCoord, &roomSize);
		rmap[i_rmap][j_rmap].roomSize = roomSize;
	}
	MakePath();
	return map;
}


void MysteryDungeonMaker::MakeRoom(Vector2* startPoint, Vector2* roomSize)
{
	int endColumnIndex = startPoint->x + sectionWidth - 1;
	int endRowIndex = startPoint->y + sectionHeight - 1;
	Vector2 puttableStartPoint;
	Vector2 puttableEndPoint;
	puttableStartPoint.x = startPoint->x + 1;
	puttableStartPoint.y = startPoint->y + 1;
	puttableEndPoint.x = endColumnIndex - roomSize->x;
	puttableEndPoint.y = endRowIndex - roomSize->y;
	
	Vector2 roomStartPoint;
	roomStartPoint.x = GetRandInRange(puttableStartPoint.x, puttableEndPoint.x);
	roomStartPoint.y = GetRandInRange(puttableStartPoint.y, puttableEndPoint.y);

	Vector2 v = ConvertToRMapCoord(*startPoint);
	rmap[v.y][v.x].roomStartPoint.x = roomStartPoint.x;
	rmap[v.y][v.x].roomStartPoint.y = roomStartPoint.y;
	rmap[v.y][v.x].roomEndPoint = Vector2(roomStartPoint.x + roomSize->x-1, roomStartPoint.y+roomSize->y-1);

	for (size_t i = 0; i < roomSize->y; i++)
	{
		for (size_t j = 0; j < roomSize->x; j++)
		{
			map[roomStartPoint.y+i][roomStartPoint.x+j] = 1;
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
			ReducedMap info = rmap[i][j];
			if (info.isRoom)
			{
				Vector2 v;
				if(i - 1>= 0)
				{
					v.x = GetRandInRange(info.roomStartPoint.x, info.roomStartPoint.x + info.roomSize.x - 1);
					v.y = info.roomStartPoint.y-1;
					int diff = info.roomStartPoint.y - i*sectionHeight;
					for (int k = 0; k < diff; k++)
					{
						map[v.y-k][v.x] = MapObject::PATH;
					}
				}
			}
		}
	}
}


Vector2 MysteryDungeonMaker::ConvertToRMapCoord(Vector2 mapCoord)
{
	Vector2 v;
	v.x = mapCoord.x / sectionWidth;
	v.y = mapCoord.y / sectionHeight;
	return v;
}
