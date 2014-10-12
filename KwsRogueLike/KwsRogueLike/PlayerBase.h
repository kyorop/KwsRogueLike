#pragma once
#include "CharacterBase.h"
class PlayerBase
	:public CharacterBase
{
public:
	int charactor[96];
	PlayerBase(int hp, int offense, int diffense, int moveSpeed);
	~PlayerBase();
	int direction;
	void Draw()override;
	void Move();
};

