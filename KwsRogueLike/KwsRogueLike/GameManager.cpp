#include "GameManager.h"
#include "Screen.h"
#include "Image.h"
#include "PlayerBase.h"
#include "Vector2.h"
#include "floor.h"
#include "Map.h"
#include "DxLib.h"

static int startTime;
static int endTime;
static int take;

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
	image->SetDrawnObject(player);
	mapManager->Accept(image);

	
	startTime = GetNowCount();
	image->Initialize();
	endTime = GetNowCount();
}

void GameManager::Main()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "start : %d", startTime);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "end : %d", endTime);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "take: %d", endTime - startTime);
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