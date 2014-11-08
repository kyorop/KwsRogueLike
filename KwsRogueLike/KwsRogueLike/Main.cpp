#include <DxLib.h>
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

	int handle_wall = LoadGraph("img/wall32.png");
	int handle_floor = LoadGraph("img/floor32.png");
	int handle_path = LoadGraph("img/GrayFloor.png");

	//const int mapWidth = 5;
	//const int mapHeight = 3;
	//const int sectionWidth = 15;
	//const int sectionHeight = 15;
	//MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	//int** map = dungeonMaker.CreateDungeon();
	//PlayerBase player(32, 32);

	enum MapState
	{
		FLOOR,
		WALL,
		PASS,
	};
	const int mapWidth = 20;
	const int mapHeight = 15;

	EnemyBase enemy(32 * (mapWidth - 2), 32 * mapHeight / 2);
	PlayerBase player(32 * 1, 32 * mapHeight / 2);

	int map[mapHeight][mapWidth];
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (i == 0 || i == mapHeight - 1)
				map[i][j] = WALL;
			else if (j == 0 || j == mapWidth - 1)
				map[i][j] = WALL;
			else
				map[i][j] = FLOOR;
		}
	}

	const int passUp = GetRandInRange(1, mapWidth - 2);
	const int passRight = GetRandInRange(1, mapHeight - 2);
	const int passDown = GetRandInRange(1, mapWidth - 2);
	const int passLeft = GetRandInRange(1, mapHeight - 2);

	map[0][passUp] = PASS;
	map[passRight][mapWidth-1] = PASS;
	map[passLeft][0] = PASS;
	map[mapHeight-1][passDown] = PASS;

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
//		for (size_t i = 0; i < sectionHeight*mapHeight; i++)
//		{
//			for (size_t j = 0; j < sectionWidth*mapWidth; j++)
//			{
//				if (map[i][j] == MysteryDungeonMaker::MapObject::WALL)
//					DrawGraph(j * 12, i * 12, handle_wall, false);
//				else if (map[i][j] == MysteryDungeonMaker::MapObject::FLOOR)
//					DrawGraph(j * 12, i * 12, handle_floor, false);
//				else if (map[i][j] == MysteryDungeonMaker::MapObject::PATH)
//					DrawGraph(j * 12, i * 12, handle_path, false);
//			}
//		}
//		enemy.Draw();
//		player.Move();
//		player.Draw();


		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				if (map[i][j] == WALL)
					DrawGraph(32 * j, 32 * i, handle_wall, true);
				else if (map[i][j] == FLOOR)
					DrawGraph(32 * j, i * 32, handle_floor, true);
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