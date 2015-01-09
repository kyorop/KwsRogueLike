#include "EnemyManager.h"
#include "GameScene.h"
#include "EnemyBase.h"
#include "Image.h"

void EnemyManager::Initialize()
{
	for (auto& enemy : enemies)
	{
		enemy->Initialize();
	}
}

void EnemyManager::Update(GameScene* game)
{
	for (auto& enemy : enemies)
	{
		enemy->Update(game);
	}
}

void EnemyManager::Finalize()
{
	for (auto& enemy : enemies)
	{
		enemy->Finalize();
	}
}

void EnemyManager::Accept(const std::shared_ptr<ImageManager>& image) const
{
	for (auto& enemy : enemies)
	{
		image->AddDrawObject(enemy);
	}
}

void EnemyManager::Add(const std::shared_ptr<EnemyBase>& enemy)
{
	enemies.push_back(enemy);
}

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}