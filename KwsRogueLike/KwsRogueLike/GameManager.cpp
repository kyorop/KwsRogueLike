#include "GameManager.h"
#include "Screen.h"
#include "Image.h"
#include "PlayerBase.h"
#include "Vector2.h"
#include "floor.h"
#include "Map.h"

GameManager::GameManager()
	:image(std::make_shared<ImageManager>()),
	screen(std::make_shared<Screen>()),
	player(std::make_shared<PlayerBase>(Vector2(0,0))),
	mapManager(std::make_shared<MapManager>(nullptr))
{
}

void GameManager::Initialize()
{
	MysteryDungeonMaker maker(GeneralConstant::mapWidth, GeneralConstant::mapHeight, GeneralConstant::sectionWidth, GeneralConstant::sectionHeight);
	auto mapPlan = maker.CreateDungeon();
	mapManager->CreateMap(mapPlan);
	mapManager->Accept(image);
	image->SetDrawnObject(player);

	image->Initialize();
}

void GameManager::Main()
{
	screen->Update(this);

	image->Draw();
}

void GameManager::Finalize()
{
	image->Finalize();
}

std::shared_ptr<PlayerBase> GameManager::GetPlayer()
{
	return player;
}

Screen GameManager::GetScreen()
{
	return *screen;
}