#include <DxLib.h>
#include "MysteryDungeonMaker.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 16);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	int handle_wall = LoadGraph("img/Wall.png");
	int handle_floor = LoadGraph("img/GrayFloor.png");

	const int mapWidth = 5;
	const int mapHeight = 3;
	const int sectionWidth = 10;
	const int sectionHeight = 10;
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	int** map = dungeonMaker.CreateDungeon();

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
				else
					int a = 1;
			}
		}

		ScreenFlip();

		if (ProcessMessage() < 0)
			break;
	}

	DxLib_End();
	
	return 0;
}