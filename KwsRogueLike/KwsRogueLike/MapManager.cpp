#include "MapManager.h"
#include "GeneralConstant.h"
#include "floor.h"
#include "vector2.h"
#include "wall.h"
#include "path.h"
#include "Image.h"
#include "Stair.h"
#include "DungeonData.h"
#include "DungeonSize.h"

using namespace GeneralConstant;
using std::vector;
using std::shared_ptr;

void MapManager::Initialize()
{
}

void MapManager::Finalize()
{
}

void MapManager::Accept(const shared_ptr<ImageManager>& image) const
{
	for (auto& object: map)
	{
		image->AddDrawObject(object);
	}	
}

void MapManager::GenerateDungeon(const DungeonSize& sizeData, const DungeonData& dungeonData)
{
	for (size_t i = 0; i < sizeData.CalcTileRowNum(); ++i)
	{
		for (size_t j = 0; j < sizeData.CalcTileColumnNum(); ++j)
		{
			if (dungeonData.IsThis(ObjTypeOnMap::STAIR, i, i))
				map.push_back(std::make_shared<Stair>(Vector2(j*img_size_width, i*img_size_height)));

			if (dungeonData.IsThis(ObjTypeOnMap::WALL, i, j))
				map.push_back(std::make_shared<Wall>(Vector2(j*img_size_width, i*img_size_height)));
			else if (dungeonData.IsThis(ObjTypeOnMap::FLOOR, i, j))
				map.push_back(std::make_shared<Floor>(Vector2(j*img_size_width, i*img_size_height)));
			else if (dungeonData.IsThis(ObjTypeOnMap::PATH, i, j))
				map.push_back(std::make_shared<Path>(Vector2(j*img_size_width, i*img_size_height)));
		}
	}
}

void MapManager::Update(GameManager* game)
{
}