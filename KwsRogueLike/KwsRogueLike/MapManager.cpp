#include "MapManager.h"
#include "GeneralConstant.h"
#include "floor.h"
#include "vector2.h"
#include "wall.h"
#include "path.h"
#include "MapInfo.h"
#include "Image.h"
#include "Stair.h"
#include "GameManager.h"

using namespace GeneralConstant;
using std::vector;
using std::shared_ptr;

void MapManager::Accept(const shared_ptr<ImageManager>& image) const
{
	for (auto& object: map)
	{
		image->AddDrawObject(object);
	}	
}

void MapManager::Update(GameManager* game)
{
}

MapManager::MapManager(const KwsRogueLike::vector_2d<MapInformation>& mapPlan)
{
	for (int i = 0; i < tileNumHeight; i++)
	{
		for (int j = 0; j < tileNumWidth; j++)
		{
			if (mapPlan[i][j].isWall)
			{
				map.push_back(std::make_shared<Wall>(Vector2(j*img_size_width, i*img_size_height)));
			}
			else if (mapPlan[i][j].isFloor)
			{
				map.push_back(std::make_shared<Floor>(Vector2(j*img_size_width, i*img_size_height)));
			}
			else if (mapPlan[i][j].isPath)
			{
				map.push_back(std::make_shared<Path>(Vector2(j*img_size_width, i*img_size_height)));
			}
			
			if (mapPlan[i][j].isStair)
			{
				map.push_back(std::make_shared<Stair>(Vector2(j*img_size_width, i*img_size_height)));
			}
		}
	}
}

MapManager::~MapManager()
{
}

void MapManager::CreateMap(const vector<vector<MapInformation>>& mapPlan)
{
}

void MapManager::DebugMode()
{
}

void MapManager::Move()
{
}
