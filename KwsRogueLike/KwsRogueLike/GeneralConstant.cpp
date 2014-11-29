#include "GeneralConstant.h"

namespace GeneralConstant
{
	const int gameSizeX = 640 * 2;
	const int gameSizeY = 480 * 1.5;
	const int playerX = (gameSizeX / 2) - 32;
	const int playerY = (gameSizeY / 2) - 16;
	const int mapWidth = 4; 
	const int mapHeight = 3;
	const int sectionWidth = 20;
	const int sectionHeight = 20;
	const int entireWidth = sectionWidth*mapWidth;
	const int entireHeight = sectionHeight*mapHeight;
	const int img_size_width = 32;
	const int img_size_height = 32;
}