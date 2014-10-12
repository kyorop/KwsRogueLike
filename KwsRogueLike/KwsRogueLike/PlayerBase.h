#pragma once
#include "CharacterBase.h"
class PlayerBase
	:CharacterBase
{
public:
	PlayerBase(int hp, int offense, int diffense, int moveSpeed);
	~PlayerBase();
};

