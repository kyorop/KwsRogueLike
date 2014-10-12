#include "MapData.h"

void MapData::Register(int x, int y,int i)
{
	switch (i)
	{
	case 0:
		mapinfo[y / 32][x / 32].isEnemy = true;
		break;
	case 1:
		mapinfo[y / 32][x / 32].isPlayer = true;
		break;
	case 2:
		mapinfo[y / 32][x / 32].isTrap = true;
		break;
	case 3:
		mapinfo[y / 32][x / 32].isItem = true;
		break;
	case 4:
		mapinfo[y / 32][x / 32].isStair = true;
		break;
	case 5:
		mapinfo[y / 32][x / 32].isWall = true;
		break;
	default:
	}
}

MapInfo** MapData::GetMapInfo()
{
	return (MapInfo**)mapinfo;
}