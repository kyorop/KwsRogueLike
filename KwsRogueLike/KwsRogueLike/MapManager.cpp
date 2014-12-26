#include "MapManager.h"
#include "GeneralConstant.h"
#include "floor.h"
#include "vector2.h"
#include "wall.h"
#include "path.h"
#include "MapInfo.h"
#include "Image.h"
#include "Stair.h"

using namespace GeneralConstant;
using std::vector;
using std::shared_ptr;

void MapManager::Accept(const shared_ptr<ImageManager>& image) const
{
	for (auto& object: map)
	{
		image->SetDrawnObject(object);
	}	
}

void MapManager::Update(GameManager* game)
{
}

MapManager::~MapManager()
{
}

void MapManager::CreateMap(const vector<vector<MapInformation>>& mapPlan)
{
	for (int i = 0; i < tileNumHeight; i++)
	{
		for (int j = 0; j < tileNumWidth; j++)
		{
			if (mapPlan[i][j].isWall)
			{
				map.push_back(std::make_shared<Wall>(Vector2(i*img_size_height, j*img_size_width)));
			}
			if (mapPlan[i][j].isFloor)
			{
				map.push_back(std::make_shared<Floor>(Vector2(i*img_size_height, j*img_size_width)));
			}
			if (mapPlan[i][j].isPath)
			{
				map.push_back(std::make_shared<Path>(Vector2(i*img_size_height, j*img_size_width)));
			}
			if (mapPlan[i][j].isStair)
			{
				map.push_back(std::make_shared<Stair>(Vector2(i*img_size_height, j*img_size_width)));
			}
		}
	}
}

void MapManager::DebugMode()
{
}

void MapManager::Move()
{
}

void MapManager::Initialize(std::vector<std::vector<MapInformation>>& mapInfo)
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			auto tile = mapInfo[i][j];
			if (tile.isFloor)
			{
				
			}
			if (tile.isStair)
			{
				
			}
			if (tile.isTrap)
			{
				
			}
			if (tile.isWall)
			{
				
			}
			if (tile.isPath)
			{
				
			}
		}
	}
}

