#include "GameScene.h"
#include "Screen.h"
#include "Image.h"
#include "MapManager.h"
#include "DxLib.h"
#include "generalconstant.h"
#include "MysteryDungeonMaker.h"
#include "ItemManager.h"
#include "PlayerBase.h"
#include "DungeonSize.h"
#include "RoomData.h"
#include "DungeonData.h"
#include "DungeonGenerator.h"
#include "GameManagerFactory.h"
#include "ItemManagerFactory.h"
#include "BlockRect.h"
#include "Component.h"
#include "GameManager.h"
#include "Strings.h"

static int startTime;
static int endTime;
static int take;

int GameScene::GetLayer()
{
	return 4;
}

void GameScene::Load(ImageManager* manager)
{
}

void GameScene::Draw(ImageManager* manager)
{
}

bool GameScene::GetDrawFlag()
{
	return true;
}

bool GameScene::IsDead()
{
	return false;
}

GameScene::GameScene()
	:image(std::make_shared<ImageManager>()),
	screen(std::make_shared<Screen>()),
	player(std::make_shared<PlayerBase>())
{
}

void GameScene::Initialize()
{
	DungeonSize dungeonSize(GeneralConstant::mapWidth, GeneralConstant::sectionWidth, GeneralConstant::mapHeight, GeneralConstant::sectionHeight);
	MysteryDungeonMaker maker(dungeonSize);
	maker.Initialize();
	dungeonData = std::make_shared<DungeonData>(maker.DungeonData());
	
	DungeonGenerator dGenerator;
	mapManager = std::make_shared<MapManager>(dGenerator.Generate(dungeonSize, *dungeonData));

	auto roomData = maker.RoomData();
	auto factory = std::unique_ptr<GameManagerFactory>(new ItemManagerFactory());
	itemManager = factory->Create(dungeonSize, roomData);

	image->AddDrawObject(std::shared_ptr<GameScene>(this, [](GameScene*){}));

	//set to image class
	image->AddDrawObject(player);
	mapManager->Accept(image);
	itemManager->Accept(image);

	auto playerStateDisplayer = std::make_shared<Strings>(currentFloor, player.get());
	image->AddDrawObject(playerStateDisplayer);

	startTime = GetNowCount();
	image->Initialize();
	endTime = GetNowCount();
}

void GameScene::Main()
{
	//update
	screen->Update(*dungeonData);
	mapManager->Update(this);
	itemManager->Update(this);
	image->Update(this);

	//draw
	image->Draw();
	DrawFormatString(0, 30, GetColor(255, 255, 255), "start : %d", startTime);
	DrawFormatString(0, 50, GetColor(255, 255, 255), "end : %d", endTime);
	DrawFormatString(0, 70, GetColor(255, 255, 255), "take: %d", endTime - startTime);
}

void GameScene::Finalize()
{
	image->Finalize();
}

std::shared_ptr<PlayerBase>& GameScene::GetPlayer()
{
	return player;
}

Screen& GameScene::GetScreen()
{
	return *screen;
}