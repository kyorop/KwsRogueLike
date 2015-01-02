#include "GameManager.h"
#include "Screen.h"
#include "Image.h"
#include "MapManager.h"
#include "DxLib.h"
#include "generalconstant.h"
#include "MysteryDungeonMaker.h"
#include "ItemManager.h"
#include "PlayerBase.h"
#include "DungeonSize.h"
#include "DungeonData.h"
#include "DungeonGenerator.h"

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
//	itemManager = std::make_shared<ItemManager>(mapPlan);
}

void GameManager::Initialize()
{
	DungeonSize dungeonSize(GeneralConstant::mapWidth, GeneralConstant::sectionWidth, GeneralConstant::mapHeight, GeneralConstant::sectionHeight);
	MysteryDungeonMaker maker(dungeonSize);
	dungeonData = std::make_shared<DungeonData>(maker.CreateMapPlan());
	
	DungeonGenerator dGenerator;
	mapManager = std::make_shared<MapManager>(dGenerator.Generate(dungeonSize, *dungeonData));

	image->AddDrawObject(std::shared_ptr<GameManager>(this, [](GameManager*){}));

	//set to image class
	image->AddDrawObject(player);
	mapManager->Accept(image);
//	itemManager->Accept(image);
	
	startTime = GetNowCount();
	image->Initialize();
	endTime = GetNowCount();
}

void GameManager::Main()
{
	//update
	screen->Update(*dungeonData);
	mapManager->Update(this);
//	itemManager->Update(this);
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

std::shared_ptr<PlayerBase>& GameManager::GetPlayer()
{
	return player;
}

Screen& GameManager::GetScreen()
{
	return *screen;
}