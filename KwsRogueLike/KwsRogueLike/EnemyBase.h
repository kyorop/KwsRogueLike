#pragma once
#include "CharacterBase.h"

class EnemyBase
	:public CharacterBase
{
public:
	EnemyBase(int hp, int offense, int diffense, int moveSpeed);
	~EnemyBase();
};

