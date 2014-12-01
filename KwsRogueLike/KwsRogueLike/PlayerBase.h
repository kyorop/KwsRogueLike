#pragma once
#include "CharacterBase.h"
#include "scrollingmovement.h"

class PlayerBase
	:public CharacterBase
{
private:
	ScrollingMovement::Direction drawDirection;
	int charactor[96];
	int gold = 0; //持っている金

public:
	PlayerBase(int x, int y);
	~PlayerBase();
	void Draw();
	void Move();
	int GetGold();
};

