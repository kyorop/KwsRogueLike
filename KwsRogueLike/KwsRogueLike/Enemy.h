#pragma once
#include "EnemyBase.h"
#include "Attack.h"

class Enemy :
	public EnemyBase,Attack
{
public:
	Enemy();
	~Enemy();
};

