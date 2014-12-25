#include "GeneralConstant.h"

namespace GeneralConstant
{
	const int WindowSizeX = 800;//ここの値は、32で割った値が奇数になるものである必要がある
	const int WindowSizeY = 600;//ここの値も上と同じであるべき
	const int playerX = (WindowSizeX/img_size_width)%2 ? (WindowSizeX / 2) - img_size_width/2 : WindowSizeX/2;
	const int playerY = (WindowSizeY / 2) - 12;
	const int mapWidth = 4; 
	const int mapHeight = 3;
	const int sectionWidth = 20;
	const int sectionHeight = 20;
	const int tileNumWidth = sectionWidth*mapWidth;
	const int tileNumHeight = sectionHeight*mapHeight;
	const int img_size_width = 32;
	const int img_size_height = 32;
}