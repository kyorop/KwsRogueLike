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
	
//			std::vector<std::vector<int>> tempMap;�����̎��_�ł�tempMap�̗v�f�ɂ͉��������ĂȂ�����A���̏�ԂœY�����A�N�Z�X����Ɣ͈͊O�A�N�Z�X�G���[�ŗ����܂��B
			for (int i = 0; i < sectionHeight*mapHeight; i++)
			{
				for (int j = 0; j < sectionWidth*mapWidth; j++)
				{
					(*map)[i][j] = ObjectTypeOnMap::FLOOR;//��map�̓|�C���^�Ȃ̂ł����������Ɏg���܂�
				}
			}

}
