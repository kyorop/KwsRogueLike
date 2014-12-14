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
#include "Map.h"
#include "MapInfo.h"
#include "Image.h"
#include "Screen.h"

using namespace GeneralConstant;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	int floor = 1; //todo 階層データどこに入れる？

	ChangeWindowMode(true);
	SetGraphMode(WindowSizeX, WindowSizeY, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	auto maker = std::make_shared<MysteryDungeonMaker>(mapWidth, mapHeight, sectionWidth, sectionHeight);
	auto mapPlan = maker->CreateDungeon();
	auto mapInfo = std::make_shared<MapInfo>(mapPlan);
	auto player = std::make_shared<PlayerBase>(Vector2(playerX, playerY));
	Strings PlayerData; //文字列表示オブジェクト

	ImageManager drawer;
	drawer.SetDrawnObject(player);

#if DEBUG //敵キャラを一体作る
	dungeon.DebugMode();
	EnemyBase *enemy1 = new EnemyBase(32 * 10, 32 * 1, 15, 8, 8, 2, 1);
#endif


	Screen screen;
	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		screen.Update();
//		map.Move();

#if DEBUG
		if (CheckHitKey(KEY_INPUT_Z))
		{
			dungeon.CreateMap();
		}
#endif

#if DEBUG
		enemy1->Draw();
#endif

		PlayerData.DisplayPlayerData(floor, player.get());
		drawer.Draw();

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}

	DxLib_End();
	
	return 0;
}