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
	void HpChanger(int value);
	
public:
	CharacterBase(int hp, int offense, int diffense, int moveSpeed);
	CharacterBase(int hp, int offense, int diffense, int moveSpeed, int level);
	~CharacterBase();
};

