#include "DebugMode.h"
#include "DxLib.h"
#include "MysteryDungeonMaker.h"


DebugMode::DebugMode()
{
}


DebugMode::~DebugMode()
{
}

void DebugMode::StartDebugMode(std::vector<std::vector<int>>* map)
{
	if (CheckHitKeyAll())
	{
		if (((CheckHitKey(KEY_INPUT_LCONTROL) != 0) && (CheckHitKey(KEY_INPUT_RCONTROL) != 0)))
		{
			const int mapWidth = 5;
			const int mapHeight = 5;
			const int sectionWidth = 15;
			const int sectionHeight = 15;
			std::vector<std::vector<int>> tempMap;
			for (int i = 0; i < sectionHeight*mapHeight; i++)
			{
				for (int j = 0; j < sectionWidth*mapWidth; j++)
				{
					tempMap[i][j] = MysteryDungeonMaker::FLOOR;
				}
			}
			*map = tempMap;
		}
	}
}
