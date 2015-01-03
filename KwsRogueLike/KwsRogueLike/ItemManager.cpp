#include <algorithm>
#include "ItemManager.h"
#include "Image.h"
#include "Meat.h"
#include "vector2.h"
#include "PlayerBase.h"
#include "GameScene.h"

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

void ItemManager::Update(GameScene* game)
{
	auto takenItem = FindSamePosItem(game->GetPlayer()->GetCoordinate());
	if (takenItem != meats.end())
	{
		game->GetPlayer()->SetItem(*takenItem);
		(*takenItem)->Kill();
		meats.erase(takenItem);
	}
}

void ItemManager::Add(const Meat& meat)
{
	meats.push_back(std::make_shared<Meat>(meat));
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::shared_ptr<Meat>>>>ItemManager::FindSamePosItem(const Vector2& playerCoord)
{
	return find_if(meats.begin(), meats.end(), [&](const std::shared_ptr<Meat>& item){return playerCoord == item->GetCoordinate(); });
}