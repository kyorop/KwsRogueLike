#include "NormalEnemy.h"
#include "MapData.h"

NormalEnemy::NormalEnemy(int hp, int offense, int diffense, int moveSpeed)
	:Enemy(hp, offense, diffense, moveSpeed)
{
	
}


NormalEnemy::~NormalEnemy()
{
}

void NormalEnemy::cAttack(int x, int y)
{
	MapInfo** mapinfo = MapData::getInstance()->GetMapInfo();
	//if (mapinfo[0][0].isEnemy)
}