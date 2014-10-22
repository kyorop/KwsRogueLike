#include <algorithm>
#include "MysteryDungeonMaker.h"
#include "RandExtended.h"
#include "Vector2.h"
#include "ReducedMap.h"
#include "Section.h"
#include "Rect.h"

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
		section[i_section][j_section].hasRoom = true;

		Rect room;
		room.x1 = sectionWidth * j_section;
		room.y1 = sectionHeight * i_section;
		room.x2 = room.x1 + GetRandInRange(4, sectionWidth - 2);
		room.y2 = GetRandInRange(4, sectionHeight - 2);
		MakeRoom(&putRoomCoord, &roomSize);
		MakeRoom(room);


		section[i_section][j_section].roomSize = roomSize;
		section[i_section][j_section].SetRoom(put)
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

	Vector2 v = ConvertToSectionCoord(*startPoint);
	section[v.y][v.x].roomStart.x = roomStartPoint.x;
	section[v.y][v.x].roomStart.y = roomStartPoint.y;
	section[v.y][v.x].roomEnd = Vector2(roomStartPoint.x + roomSize->x-1, roomStartPoint.y+roomSize->y-1);

	for (size_t i = 0; i < roomSize->y; i++)
	{
		for (size_t j = 0; j < roomSize->x; j++)
		{
			map[roomStartPoint.y+i][roomStartPoint.x+j] = 1;
		}
	}
}

void MysteryDungeonMaker::MakeRoom(Rect const& room)
{

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
			Section info = section[i][j];
			if (info.hasRoom)
			{
				Vector2 v;
				if(i - 1>= 0)
				{
					v.x = GetRandInRange(info.roomStart.x, info.roomStart.x + info.roomSize.x - 1);
					v.y = info.roomStart.y-1;
					int diff = info.roomStart.y - i*sectionHeight;
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
