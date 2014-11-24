#pragma once
#include "EnemyBase.h"

class Enemy :
	public EnemyBase
{
public:
public:
	Enemy(int hp, int offense, int diffense, int moveSpeed,int level);
	~Enemy();
};

