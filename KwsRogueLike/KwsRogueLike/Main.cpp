#include <DxLib.h>
#include "MysteryDungeonMaker.h"
#include "PlayerBase.h"
#include "EnemyBase.h"

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

	const int mapWidth = 5;
	const int mapHeight = 3;
	const int sectionWidth = 15;
	const int sectionHeight = 15;
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	int** map = dungeonMaker.CreateDungeon();
	PlayerBase player(32, 32);
	EnemyBase enemy(3,3,3,3);

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

		enum MapState
		{
			FLOOR,
			WALL,
		};
		const int mapWidth = 20;
		const int mapHeight = 15;
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

		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				if (map[i][j] == WALL)
					DrawGraph(32 * j, 32 * i, handle_wall, true);
				else
					DrawGraph(32 * j, i * 32, handle_floor, true);
			}
		}

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}

	DxLib_End();
	
	return 0;
}