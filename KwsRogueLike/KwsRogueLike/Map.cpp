#include "Map.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"


Map::Map()
{
	MysteryDungeonMaker dungeonMaker(GeneralConstant::mapWidth, GeneralConstant::mapHeight, GeneralConstant::sectionWidth, GeneralConstant::sectionHeight);

	dungeonMaker.SetRoomNum(199);
	dungeonMaker.CreateDungeon(&map);
}


Map::~Map()
{
}

int Map::GetFloor()
{
	return floor;
}