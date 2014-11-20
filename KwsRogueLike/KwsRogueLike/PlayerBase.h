#pragma once
#include "CharacterBase.h"

class PlayerBase
	:public CharacterBase
{
private:
	Direction direction;
	int charactor[96];

public:
	PlayerBase(int hp, int offense, int diffense, int moveSpeed);
	PlayerBase(int x, int y);
	~PlayerBase();
	void Draw()override;
	void Move();
};

