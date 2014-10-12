#pragma once
#include "ScrollableObject.h"

class CharacterBase
	:public ScrollableObject
{
private:
	int hp, offense, diffense, level, moveSpeed;

protected:
	void GetHp(int hp);
	void Damage(int damage);
	
	CharacterBase();
	~CharacterBase();
};

