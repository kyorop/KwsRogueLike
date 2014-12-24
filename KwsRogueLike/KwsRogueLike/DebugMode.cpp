#include "DebugMode.h"
#include "DxLib.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"
#include "MapInfo.h"
using namespace GeneralConstant;

DebugMode::DebugMode()
{
}


DebugMode::~DebugMode()
{
}

void DebugMode::StartDebugMode(std::vector<std::vector<ObjectTypeOnMap>>* map)
{
	
//			std::vector<std::vector<int>> tempMap;←この時点ではtempMapの要素には何も入ってないから、その状態で添え字アクセスすると範囲外アクセスエラーで落ちます。
			for (int i = 0; i < sectionHeight*mapHeight; i++)
			{
				for (int j = 0; j < sectionWidth*mapWidth; j++)
				{
					(*map)[i][j] = ObjectTypeOnMap::FLOOR;//←mapはポインタなのでこういう風に使います
				}
			}

}
