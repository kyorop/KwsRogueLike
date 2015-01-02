#include "MapManager.h"
#include "GeneralConstant.h"
#include "Image.h"

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

void MapManager::Add(const shared_ptr<IDrawable>& tile)
{
	map.push_back(tile);
}

void MapManager::Update(GameManager* game)
{
}