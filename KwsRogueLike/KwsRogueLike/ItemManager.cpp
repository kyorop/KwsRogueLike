#include <algorithm>
#include "ItemManager.h"
#include "Image.h"
#include "DungeonData.h"
#include "Meat.h"
#include "GeneralConstant.h"
#include "vector2.h"
#include "GameManager.h"
#include "PlayerBase.h"

ItemManager::ItemManager(KwsRogueLike::vector_2d<ObjDataOnTile> infos)
{
	for (size_t i = 0; i < infos.size(); i++)
	{
		for (size_t j = 0; j < infos[i].size(); j++)
		{
			if (infos[i][j].Find(ObjTypeOnMap::ITEM))
			{
				meats.push_back(std::make_shared<Meat>(Vector2(j* GeneralConstant::img_size_width, i* GeneralConstant::img_size_height)));
			}
		}
	}
}

void ItemManager::Initialize()
{
}

void ItemManager::Finalize()
{
}

void ItemManager::Accept(const std::shared_ptr<ImageManager>& image) const
{
	for (auto& meat : meats)
	{
		image->AddDrawObject(meat);
	}
}

void ItemManager::Update(GameManager* game)
{
	auto takenItem = FindSamePosItem(game->GetPlayer()->GetCoordinate());
	if (takenItem != meats.end())
	{
		game->GetPlayer()->SetItem(*takenItem);
		(*takenItem)->Kill();
		meats.erase(takenItem);
	}
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::shared_ptr<Meat>>>>ItemManager::FindSamePosItem(const Vector2& playerCoord)
{
	return find_if(meats.begin(), meats.end(), [&](const std::shared_ptr<Meat>& item){return playerCoord == item->GetCoordinate(); });
}