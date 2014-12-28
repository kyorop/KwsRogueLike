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

int GameManager::GetLayer()
{
	return 4;
}

void GameManager::Load(ImageManager* manager)
{
}

void GameManager::Draw(ImageManager* manager)
{
}

bool GameManager::GetDrawFlag()
{
	return true;
}

bool GameManager::IsDead()
{
	return false;
}

GameManager::GameManager()
	:image(std::make_shared<ImageManager>()),
	screen(std::make_shared<Screen>()),
	player(std::make_shared<PlayerBase>())
{
	MysteryDungeonMaker maker(GeneralConstant::mapWidth, GeneralConstant::mapHeight, GeneralConstant::sectionWidth, GeneralConstant::sectionHeight);
	mapPlan = maker.CreateMapPlan();
	mapManager = std::make_shared<MapManager>(mapPlan);
	itemManager = std::make_shared<ItemManager>(mapPlan);
}

void GameManager::Initialize()
{
	image->AddDrawObject(std::shared_ptr<GameManager>(this, [](GameManager*){}));

	//set to image class
	image->AddDrawObject(player);
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

const std::vector<std::vector<MapInformation>>& GameManager::GetMapInfo()
{
	return this->mapPlan;
}

std::shared_ptr<PlayerBase>& GameManager::GetPlayer()
{
	return player;
}

Screen& GameManager::GetScreen()
{
	return *screen;
}