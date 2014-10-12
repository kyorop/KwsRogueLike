#pragma once
#include "EnemyBase.h"
#include "Attack.h"

class Enemy :
	public EnemyBase,Attack
{
public:
	Enemy(int hp, int offense, int diffense, int moveSpeed);
	~Enemy();
};

