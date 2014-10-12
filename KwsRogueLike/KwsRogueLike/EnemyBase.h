#pragma once
#include "CharacterBase.h"
class EnemyBase
	:public CharacterBase
{
public:
	int charactor[96];
	EnemyBase();
	~EnemyBase();

	void Draw()override;
};

