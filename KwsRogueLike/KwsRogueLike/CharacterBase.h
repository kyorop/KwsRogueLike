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
	void HpChanger(int value);
	
public:
	~CharacterBase();
	CharacterBase(int hp, int offense, int diffense, int moveSpeed);
	CharacterBase(int hp, int offense, int diffense, int moveSpeed, int level);
};

