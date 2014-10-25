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

	int handle_wall = LoadGraph("img/item/Wall.png");
	int handle_floor = LoadGraph("img/BrownFloor.png");
	int handle_path = LoadGraph("img/GrayFloor.png");

	const int mapWidth = 5;
	const int mapHeight = 5;
	const int sectionWidth = 10;
	const int sectionHeight = 10;
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	int** map = dungeonMaker.CreateDungeon();
	PlayerBase player(4,4,4,4);
	EnemyBase enemy(3,3,3,3);

	while (!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		for (size_t i = 0; i < sectionHeight*mapHeight; i++)
		{
			for (size_t j = 0; j < sectionWidth*mapWidth; j++)
			{
				if (map[i][j] == MysteryDungeonMaker::MapObject::WALL)
					DrawGraph(j * 12, i * 12, handle_wall, false);
				else if (map[i][j] == MysteryDungeonMaker::MapObject::FLOOR)
					DrawGraph(j * 12, i * 12, handle_floor, false);
				else if (map[i][j] == MysteryDungeonMaker::MapObject::PATH)
					DrawGraph(j * 12, i * 12, handle_path, false);
			}
		}
		enemy.Draw();
		player.Move();
		player.Draw();
		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}

	DxLib_End();
	
	return 0;
}