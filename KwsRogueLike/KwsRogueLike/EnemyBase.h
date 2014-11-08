#pragma once
#include "CharacterBase.h"
class EnemyBase
	:public CharacterBase
{
public:
	int charactor[96];
	EnemyBase(int hp, int offense, int diffense, int moveSpeed);
	EnemyBase(int x, int y);
	~EnemyBase();

	void Draw()override;
};

