#include <DxLib.h>
#include <vector>
#include "MysteryDungeonMaker.h"
#include "PlayerBase.h"
#include "EnemyBase.h"
#include "RandExtended.h"
#include "DebugMode.h"
#include "GeneralConstant.h"

#define DEBUG 0
#include "Strings.h"
#include "MapInfo.h"
#include "Image.h"
#include "Screen.h"
#include "GameManager.h"

using namespace GeneralConstant;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	int floor = 1; //todo �K�w�f�[�^�ǂ��ɓ����H

	ChangeWindowMode(true);
	SetGraphMode(WindowSizeX, WindowSizeY, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);

//	auto maker = std::make_shared<MysteryDungeonMaker>(mapWidth, mapHeight, sectionWidth, sectionHeight);
//	auto mapPlan = maker->CreateDungeon();
//	auto mapInfo = std::make_shared<MapInfo>(mapPlan);
//	auto player = std::make_shared<PlayerBase>(Vector2(playerX, playerY));
//	Strings PlayerData; //������\���I�u�W�F�N�g

	GameManager game;

#if DEBUG //�G�L��������̍��
	dungeon.DebugMode();
	EnemyBase *enemy1 = new EnemyBase(32 * 10, 32 * 1, 15, 8, 8, 2, 1);
#endif

	game.Initialize();

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
#if DEBUG
		if (CheckHitKey(KEY_INPUT_Z))
		{
			dungeon.CreateMap();
		}
#endif

		game.Main();

#if DEBUG
		enemy1->Draw();
#endif
		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}
	game.Finalize();

	DxLib_End();
	
	return 0;
}