#include "Map.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"
#include "Dxlib.h"
#include "floor.h"
#include "vector2.h"
#include "wall.h"
#include "floor.h"
#include "path.h"
#include "ScrollingMovement.h"

using namespace GeneralConstant;
using std::vector;
using std::shared_ptr;

Map::Map()
{
	floor = 1;
	scroller = std::make_shared<ScrollingMovement>();
}


void Map::CreateMap()
{
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	dungeonMaker.SetRoomNum(199);
	auto tempMap = dungeonMaker.CreateDungeon();
	for (int i = 0; i < entireHeight; i++)
	{
		map.push_back(vector<shared_ptr<ObjectBase>>());
		for (int j = 0; j < entireWidth; j++)
		{
			switch (tempMap[i][j])
			{
			case MysteryDungeonMaker::WALL:
				map[i].push_back(std::make_shared<Wall>(Vector2(i*img_size_height, j*img_size_width)));
				break;
			case MysteryDungeonMaker::FLOOR:
				map[i].push_back(std::make_shared<Floor>(Vector2(i*img_size_height, j*img_size_width)));
				break;
			case MysteryDungeonMaker::PATH:
				map[i].push_back(std::make_shared<Path>(Vector2(i*img_size_height, j*img_size_width)));
				break;
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
}

void Map::Move()
{
	Vector2 currentCoordinate(0,0);
	scroller->Scroll(&currentCoordinate);
	for (int i = 0; i < entireHeight; i++)
	{
		for (int j = 0; j < entireWidth; j++)
		{
			map[i][j]->AddCoordinate(currentCoordinate);
		}
	}
}

bool Map::IsMovable()
{
	return true;
}

void Map::Draw()
{
	for (int i=0; i < entireHeight; i++)
	{
		for (int j=0; j < entireWidth; j++)
		{
			map[i][j]->Draw();
		}
	}
}