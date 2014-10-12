#pragma once
#include "Enemy.h"
class NormalEnemy :
	public Enemy
{
public:
	NormalEnemy(int hp, int offense, int diffense, int moveSpeed, int level);
	void cAttack(int x,int y);
	~NormalEnemy();
};

