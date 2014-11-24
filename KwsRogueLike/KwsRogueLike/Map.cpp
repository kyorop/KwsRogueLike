#include "Map.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"
#include "Dxlib.h"

using namespace GeneralConstant;

Map::Map()
{
	floor = 1;
	MysteryDungeonMaker dungeonMaker(GeneralConstant::mapWidth, GeneralConstant::mapHeight, GeneralConstant::sectionWidth, GeneralConstant::sectionHeight);
	dungeonMaker.SetRoomNum(199);
	dungeonMaker.CreateDungeon(&map);
	handle_wall = LoadGraph("img/background/wall.png");
	handle_floor = LoadGraph("img/background/floor.png");
	handle_path = LoadGraph("img/background/path.png");
	DrawDungeon();
}


Map::~Map()
{
}

int Map::GetFloor()
{
	return floor;
}

void Map::DrawDungeon()
{
	for (int i = 0; i < mapHeight* sectionHeight; i++)
	{
		for (int j = 0; j < mapWidth* sectionWidth; j++)
		{
			if (map[i][j] == MysteryDungeonMaker::WALL)
				DrawGraph(img_size_width * j, img_size_height * i, handle_wall, true);
			else if (map[i][j] == MysteryDungeonMaker::FLOOR)
				DrawGraph(img_size_width * j, img_size_height * i, handle_floor, true);
			else if (map[i][j] == MysteryDungeonMaker::PATH)
				DrawGraph(img_size_width * j, img_size_height * i, handle_path, true);
		}
	}
}

void Map::DebugMode()
{
	for (int i = 0; i < sectionHeight*mapHeight; i++)
	{
		for (int j = 0; j < sectionWidth*mapWidth; j++)
		{
			map[i][j] = MysteryDungeonMaker::FLOOR;//←mapはポインタなのでこういう風に使います
		}
	}
}