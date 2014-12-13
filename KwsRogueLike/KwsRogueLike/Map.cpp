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
#include "MapInfo.h"
#include "Component.h"
#include <random>

using namespace GeneralConstant;
using std::vector;
using std::shared_ptr;

Map::Map(shared_ptr<MapInfo> mapInfo)
	:mapInfo(mapInfo)
{
	floor = 1;
	scroller = std::make_shared<ScrollingMovement>();
}

Map::~Map()
{
}


void Map::Scroll(const Vector2& scrollAmount)
{
	for (int i = 0; i < entireHeight; i++)
	{
		for (int j = 0; j < entireWidth; j++)
		{
			map[i][j]->AddCoordinate(scrollAmount);
		}
	}
}

void Map::CreateMap(const vector<vector<MysteryDungeonMaker::MapComponent>>& mapPlan)
{
	vector<Component> floorStore;

	for (int i = 0; i < entireHeight; i++)
	{
		map.push_back(vector<shared_ptr<ObjectBase>>());
		for (int j = 0; j < entireWidth; j++)
		{
			switch (mapPlan[i][j])
			{
			case MysteryDungeonMaker::WALL:
				map[i].push_back(std::make_shared<Wall>(Vector2(i*img_size_height, j*img_size_width)));
				break;
			case MysteryDungeonMaker::FLOOR:
				map[i].push_back(std::make_shared<Floor>(Vector2(i*img_size_height, j*img_size_width)));
				floorStore.push_back(Component(i, j));
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

	std::random_device rd;
	shuffle(begin(floorStore), end(floorStore), std::mt19937_64(rd()));
	Vector2 floorCoord = Vector2(-floorStore[0].j * 32+playerX, -floorStore[0].i * 32+playerY);
	Scroll(floorCoord);
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
	Vector2 scrollAmount(0,0);
	scroller->Scroll(&scrollAmount);

//	if (!scroller->IsMoving())
	//{
	//	if (mapInfo->GetInformation(map[0][0]->GetCoordinate(), Vector2(playerX - scrollAmount.x, playerY)).isWall
	//		|| mapInfo->GetInformation(map[0][0]->GetCoordinate(), Vector2(playerX + 32 + scrollAmount.x, playerY)).isWall
	//		|| mapInfo->GetInformation(map[0][0]->GetCoordinate(), Vector2(playerX, playerY - scrollAmount.y)).isWall
	//		|| mapInfo->GetInformation(map[0][0]->GetCoordinate(), Vector2(playerX, playerY + 32 + scrollAmount.y)).isWall)
	//	{
	//		scrollAmount.Set(0, 0);
	//	}
	//}


	Scroll(scrollAmount);
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