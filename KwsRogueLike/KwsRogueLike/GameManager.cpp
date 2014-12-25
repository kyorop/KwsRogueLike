#include "GameManager.h"
#include "Screen.h"
#include "Image.h"
#include "Vector2.h"
#include "MapManager.h"
#include "DxLib.h"
#include "MapInfo.h"
#include "generalconstant.h"
#include "MysteryDungeonMaker.h"
#include "PlayerBase.h"
#include "ItemManager.h"

static int startTime;
static int endTime;
static int take;

GameManager::GameManager()
	:image(std::make_shared<ImageManager>()),
	screen(std::make_shared<Screen>()),
	player(std::make_shared<PlayerBase>()),
	mapManager(std::make_shared<MapManager>()),
	itemManager(std::make_shared<ItemManager>()),
	mapInfos(GeneralConstant::tileNumHeight, std::vector<MapInformation>(GeneralConstant::tileNumWidth))
{
}

void GameManager::Initialize()
{
	MysteryDungeonMaker maker(GeneralConstant::mapWidth, GeneralConstant::mapHeight, GeneralConstant::sectionWidth, GeneralConstant::sectionHeight);
	auto mapPlan = maker.CreateDungeon();
	//initialize
	mapManager->CreateMap(mapPlan);
	itemManager->CreateItem(mapPlan);

	//set to image class
	image->SetDrawnObject(player);
	mapManager->Accept(image);
	itemManager->Accept(image);
	
	startTime = GetNowCount();
	image->Initialize();
	endTime = GetNowCount();
}

void GameManager::Main()
{
	//update
	screen->Update(this);
	mapManager->Update(this);
	itemManager->Update(this);
	image->Update(this);

	//draw
	image->Draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "start : %d", startTime);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "end : %d", endTime);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "take: %d", endTime - startTime);
}

void GameManager::Finalize()
{
	image->Finalize();
}

std::vector<std::vector<MapInformation>>& GameManager::GetMapInfo()
{
	return this->mapInfos;
}

std::shared_ptr<PlayerBase>& GameManager::GetPlayer()
{
	return player;
}

Screen& GameManager::GetScreen()
{
	return *screen;
}