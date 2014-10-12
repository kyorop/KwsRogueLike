#pragma once
#include "CharacterBase.h"
class PlayerBase
	:public CharacterBase
{
public:
	int charactor[96];
	PlayerBase();
	~PlayerBase();

	void Draw()override;
	void Move();
};

