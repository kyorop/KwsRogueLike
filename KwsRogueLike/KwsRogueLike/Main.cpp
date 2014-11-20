#include <DxLib.h>
#include <vector>
#include "MysteryDungeonMaker.h"
#include "PlayerBase.h"
#include "EnemyBase.h"
#include "RandExtended.h"
#include "DebugMode.h"
#include "GeneralConstant.h"

#define DEBUG 0

using namespace GeneralConstant;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640*2, 480*2, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	int handle_wall = LoadGraph("img/background/wall.png");
	int handle_floor = LoadGraph("img/background/floor.png");
	int handle_path = LoadGraph("img/background/path.png");
	const int img_size_width = 12;
	const int img_size_height = 12;

	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	std::vector <std::vector<int>> map;
	dungeonMaker.SetRoomNum(199);
	dungeonMaker.CreateDungeon(&map);

	PlayerBase player(32 * 1, 32 * (mapHeight/2));
	//EnemyBase enemy(32 * (mapWidth - 2), 32 * (mapHeight / 2));
	//enemy.SetCharacter(&player);

	DebugMode debugger; //デバッグ用のオブジェクト

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_Z))
		{
			dungeonMaker.CreateDungeon(&map);
		}


		player.Move();


#if DEBUG		
		debugger.StartDebugMode(&map);

		EnemyBase *enemy1 = new EnemyBase(32 * 10, 32 * 1, 15, 8, 8, 2, 1);
#endif

		for (int i = 0; i < mapHeight* sectionHeight; i++)
		{
			for (int j = 0; j < mapWidth* sectionWidth; j++)
			{
				if (map[i][j] == MysteryDungeonMaker::WALL)
					DrawGraph(img_size_width * j, img_size_height * i, handle_wall, true);
				else if (map[i][j] == MysteryDungeonMaker::FLOOR)
					DrawGraph(img_size_width * j, img_size_height * i, handle_floor, true);
				else if (map[i][j] == MysteryDungeonMaker::PATH)
					DrawGraph(img_size_width * j, img_size_height * i, handle_path, true);
			}
		}
		
		player.Draw();

#if DEBUG
		enemy1->Draw(); //一定時間後に消える・・・。
#endif
		

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;

	}

	DxLib_End();
	
	return 0;
}