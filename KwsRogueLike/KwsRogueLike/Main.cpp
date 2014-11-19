#include <DxLib.h>
#include <vector>
#include "MysteryDungeonMaker.h"
#include "PlayerBase.h"
#include "EnemyBase.h"
#include "RandExtended.h"
#include "DebugMode.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640*2, 480*2, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	int handle_wall = LoadGraph("img/GrayFloor.png");
	int handle_floor = LoadGraph("img/BrownFloor.png");
	int handle_path = LoadGraph("img/GrayFloor.png");
	const int img_size_width = 12;
	const int img_size_height = 12;

	const int mapWidth = 5;
	const int mapHeight = 3;
	const int sectionWidth = 20;
	const int sectionHeight = 20;
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	std::vector <std::vector<int>> map;
	dungeonMaker.SetRoomNum(199);
	dungeonMaker.CreateDungeon(&map);

	EnemyBase enemy(32 * (mapWidth - 2), 32 * (mapHeight / 2));
	PlayerBase player(32 * 1, 32 * (mapHeight/2));
	enemy.SetCharacter(&player);

	DebugMode debugger; //デバッグ用のオブジェクト

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_Z))
		{
			dungeonMaker.CreateDungeon(&map);
		}



		for (int i = 0; i < mapHeight*sectionHeight; i++)
		{
			for (int j = 0; j < mapWidth*sectionWidth; j++)
			{
				if (map[i][j] == MysteryDungeonMaker::WALL)
					DrawGraph(img_size_width * j, img_size_height * i, handle_wall, true);
				else if (map[i][j] == MysteryDungeonMaker::FLOOR)
					DrawGraph(img_size_width * j, img_size_height * i, handle_floor, true);
			}
		}

		
		
		player.Draw();
		player.Move();
		enemy.Draw();
		

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;

	}

	DxLib_End();
	
	return 0;
}