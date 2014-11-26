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

using namespace GeneralConstant;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	int floor = 1; //todo 階層データどこに入れる？

	ChangeWindowMode(true);
	SetGraphMode(640*2, 480*1.5, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Map dungeon;
	dungeon.CreateMap();

#if DEBUG //敵キャラを一体作る
	dungeon.DebugMode();
	EnemyBase *enemy1 = new EnemyBase(32 * 10, 32 * 1, 15, 8, 8, 2, 1);
#endif

	PlayerBase player(playerX,playerY);
	Strings PlayerData; //文字列表示オブジェクト


	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		dungeon.Move();
		player.Move();

#if DEBUG
		if (CheckHitKey(KEY_INPUT_Z))
		{
			dungeon.CreateMap();
		}
#endif

#if DEBUG
		enemy1->Draw();
#endif

		dungeon.Draw();
		player.Draw();
		PlayerData.DisplayPlayerData(floor, &player);
		

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}

	DxLib_End();
	
	return 0;
}