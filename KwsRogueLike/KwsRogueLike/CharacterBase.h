#pragma once
#include "ScrollableObject.h"

class CharacterBase
	:public ScrollableObject
{
private:
	int hp, offense, diffense, level=1, moveSpeed;

protected:
	void GetHp(int hp);
	void Damage(int damage);
	
	CharacterBase();
	~CharacterBase();
};

