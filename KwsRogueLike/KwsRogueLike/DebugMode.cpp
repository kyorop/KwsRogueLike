#include "DebugMode.h"
#include "DxLib.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"
using namespace GeneralConstant;

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
//			std::vector<std::vector<int>> tempMap;←この時点ではtempMapの要素には何も入ってないから、その状態で添え字アクセスすると範囲外アクセスエラーで落ちます。
			for (int i = 0; i < sectionHeight*mapHeight; i++)
			{
				for (int j = 0; j < sectionWidth*mapWidth; j++)
				{
					(*map)[i][j] = MysteryDungeonMaker::FLOOR;//←mapはポインタなのでこういう風に使います
				}
			}
//			*map = tempMap;
		}
	}
}
