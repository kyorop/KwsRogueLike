#pragma once
#include "GameConstant.h"
#include "MapInfo.h"
class MapData
{
private:
	MapInfo mapinfo[mapHeight][mapWidth];
	MapData(void){};
	static MapData* mapdata;
public:
	static MapData* getInstance(void)
	{
		return mapdata;
	}
	void Register(int x,int y,int i);
	void end(void);


	MapInfo** GetMapInfo();
};

