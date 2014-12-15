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

void MapManager::Update(std::shared_ptr<GameManager> game) const
{
}

MapManager::MapManager(shared_ptr<MapInfo> mapInfo)
	:mapInfo(mapInfo),
	stop(false)
{
	floor = 1;
	scroller = std::make_shared<ScrollingMovement>();
}

MapManager::~MapManager()
{
}


void MapManager::Scroll(const Vector2& scrollAmount)
{
	for (int i = 0; i < entireHeight; i++)
	{
		for (int j = 0; j < entireWidth; j++)
		{
			map[i][j]->AddCoordinate(scrollAmount);
		}
	}
}

void MapManager::CreateMap(const vector<vector<MysteryDungeonMaker::MapComponent>>& mapPlan)
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

int MapManager::GetFloor()
{
	return floor;
}

void MapManager::DebugMode()
{
}

void MapManager::Move()
{
	Vector2 scrollAmount(0, 0);
	if (!scroller->IsMoving())
	{
		stop = true;
	}
	
	if (!stop)
		scroller->Scroll(&scrollAmount);
	Scroll(scrollAmount);
}

bool MapManager::IsMovable()
{
	return true;
}

void MapManager::Draw(const Screen& screen)
{
	for (int i = 0; i < entireHeight; i++)
	{
		for (int j = 0; j < entireWidth; j++)
		{
			map[i][j]->Draw(screen);
		}
	}
}

void MapManager::Draw()
{
	for (int i=0; i < entireHeight; i++)
	{
		for (int j=0; j < entireWidth; j++)
		{
			map[i][j]->Draw();
		}
	}
}