#pragma once
#include "CharacterBase.h"
class PlayerBase
	:public CharacterBase
{
private:
	int satiety;
public:
	PlayerBase(hp, offense, diffense,  moveSpeed, level);
	~PlayerBase();
};

