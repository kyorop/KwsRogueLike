#pragma once
#include "CharacterBase.h"
class PlayerBase
	:public CharacterBase
{
public:
	int charactor;
	PlayerBase();
	~PlayerBase();

	void Draw()override;
};

