﻿#include "ItemManager.h"
#include "Image.h"
#include "MapInfo.h"
#include "Meat.h"
#include "GeneralConstant.h"
#include "vector2.h"
#include "GameManager.h"
#include "PlayerBase.h"
#include "Screen.h"

ItemManager::ItemManager(KwsRogueLike::vector_2d<MapInformation> infos)
{
	for (size_t i = 0; i < infos.size(); i++)
	{
		for (size_t j = 0; j < infos[i].size(); j++)
		{
			if (infos[i][j].isItem)
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
	for (auto itr = meats.begin(); itr != meats.end(); ++itr)
	{
		if ((*itr)->GetCoordinate() == game->GetPlayer()->GetCoordinate())
		{
			game->GetPlayer()->SetItem(*itr);
			(*itr)->Kill();
			meats.erase(itr);
			break;
		}
	}
}