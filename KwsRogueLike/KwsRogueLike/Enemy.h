#pragma once
#include "EnemyBase.h"
#include "IAttack.h"

class Enemy :
	public EnemyBase, virtual IAttack
{
public:
	void attack() override;
public:
	Enemy(int hp, int offense, int diffense, int moveSpeed);
	~Enemy();
};

