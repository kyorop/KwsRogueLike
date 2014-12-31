#include "DebugMode.h"
#include "GeneralConstant.h"
#include "DungeonData.h"
using namespace GeneralConstant;

DebugMode::DebugMode()
{
}


DebugMode::~DebugMode()
{
}

void DebugMode::StartDebugMode(std::vector<std::vector<ObjTypeOnMap>>* map)
{
	
			for (int i = 0; i < sectionHeight*mapHeight; i++)
			{
				for (int j = 0; j < sectionWidth*mapWidth; j++)
				{
					(*map)[i][j] = ObjTypeOnMap::FLOOR;
				}
			}

}
