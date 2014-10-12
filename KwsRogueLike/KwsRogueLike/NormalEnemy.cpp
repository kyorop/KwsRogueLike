#include "NormalEnemy.h"
#include "MapData.h"

NormalEnemy::NormalEnemy(int hp, int offense, int diffense, int moveSpeed, int level)
	:Enemy(hp, offense, diffense, moveSpeed, level)
{
	
}


NormalEnemy::~NormalEnemy()
{
}

void cAttack(int x,int y)
{
	MapInfo** mapinfo = MapData::getInstance()->GetMapInfo();
	//if (mapinfo[0][0].isEnemy)
}