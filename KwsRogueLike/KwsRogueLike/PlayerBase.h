#pragma once
#include "CharacterBase.h"

class PlayerBase
	:public CharacterBase
{
private:
	Direction drawDirection;
	int charactor[96];
	int gold = 0; //持っている金

public:
	PlayerBase(int x, int y);
	~PlayerBase();
	void Draw();
	void Move();
	int GetGold();
};

