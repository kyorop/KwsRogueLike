#include "GameManager.h"
#include "Screen.h"
#include "Image.h"
#include "PlayerBase.h"

GameManager::GameManager()
	:image(std::make_shared<ImageManager>()),
	screen(std::make_shared<Screen>()),
	player(std::make_shared<PlayerBase>(Vector2(0,0)))
{
}

void GameManager::Initialize()
{
	image->SetDrawnObject(player.get());
	image->Initialize();
}

void GameManager::Main()
{
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