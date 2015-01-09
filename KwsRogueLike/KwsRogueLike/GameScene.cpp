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
#include "EnemyManagerFactory.h"
#include "IGameProcess.h"

static int startTime;
static int endTime;
static int take;

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
	auto mapManager = std::make_shared<MapManager>(dGenerator.Generate(dungeonSize, *dungeonData));
	auto roomData = maker.RoomData();

	ItemManagerFactory itemManagerFactory;
	auto itemManager = itemManagerFactory.Create(dungeonSize, roomData);

	EnemyManagerFactory enemyMngFactory;
	auto enemyMng = enemyMngFactory.Create(dungeonSize, roomData);

	auto playerStateDisplayer = std::make_shared<Strings>(currentFloor, player.get());
	
	gameProcesses.push_back(screen);
	gameProcesses.push_back(enemyMng);
	gameProcesses.push_back(mapManager);
	gameProcesses.push_back(itemManager);
	gameProcesses.push_back(image);

	//set to image class
	image->AddDrawObject(player);
	image->AddDrawObject(playerStateDisplayer);
	mapManager->Accept(image);
	itemManager->Accept(image);
	enemyMng->Accept(image);


	for (auto& gameController : gameProcesses)
	{
		gameController->Initialize();
	}
}

void GameScene::Main()
{
	for (auto& gameController : gameProcesses)
	{
		gameController->Update(this);
	}

	image->Draw();
}

void GameScene::Finalize()
{
	for (auto& gameController : gameProcesses)
	{
		gameController->Finalize();
	}
}

std::shared_ptr<PlayerBase>& GameScene::GetPlayer()
{
	return player;
}

const DungeonData& GameScene::GetDungeonData()
{
	return *dungeonData;
}

Screen& GameScene::GetScreen()
{
	return *screen;
}