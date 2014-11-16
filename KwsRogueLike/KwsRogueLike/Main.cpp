#include <DxLib.h>
#include <vector>
#include "MysteryDungeonMaker.h"
#include "PlayerBase.h"
#include "EnemyBase.h"
#include "RandExtended.h"

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
	const int mapHeight = 5;
	const int sectionWidth = 15;
	const int sectionHeight = 15;
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	std::vector <std::vector<int>> map;
	dungeonMaker.CreateDungeon(&map);
	
	EnemyBase enemy(32 * (mapWidth - 2), 32 * mapHeight / 2);
	PlayerBase player(32 * 1, 32 * mapHeight / 2);

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();


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

		player.Move();
		player.Draw();
		enemy.Draw();
		

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}

	DxLib_End();
	
	return 0;
}