#include "Map.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"
#include "Dxlib.h"
#include "MapObject.h"
#include "floor.h"

class Wall;
using namespace GeneralConstant;

Map::Map()
{
	floor = 1;
}

void Map::CreateMap()
{
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	dungeonMaker.SetRoomNum(199);
	std::vector<std::vector<MysteryDungeonMaker::MapComponent>> tempMap = dungeonMaker.CreateDungeon();
	for (int i = 0; i < entireHeight; i++)
	{
		for (int j = 0; j < entireWidth; j++)
		{
			switch (tempMap[i][j])
			{
			case MysteryDungeonMaker::WALL: 
				map[i][j] = std::make_shared<Wall>();
				break;
			case MysteryDungeonMaker::FLOOR: 
				map[i][j] = std::make_shared<Floor>();
				break;
			case MysteryDungeonMaker::PATH: break;
			case MysteryDungeonMaker::UNBRAKABLEWALL: break;
			case MysteryDungeonMaker::STAIR: break;
			default: break;
			}
		}
	}
}


Map::~Map()
{
}

int Map::GetFloor()
{
	return floor;
}

void Map::DebugMode()
{
	for (int i = 0; i < sectionHeight*mapHeight; i++)
	{
		for (int j = 0; j < sectionWidth*mapWidth; j++)
		{
			map[i][j].SetMapComponent(MysteryDungeonMaker::FLOOR);
		}
	}
}

void Map::Move()
{
	for (int i=0; i < sectionHeight*mapHeight; i++)
	{
		for (int j=0; j < sectionWidth*mapHeight; j++)
		{
			map[i][j].Scroll();
		}
	}
}

bool Map::IsMovable()
{
	return true;
}

void Map::Draw()
{
	for (int i=0; i < sectionHeight*mapHeight; i++)
	{
		for (int j=0; j < sectionWidth*mapHeight; j++)
		{
			map[i][j].Draw();
		}
	}
}