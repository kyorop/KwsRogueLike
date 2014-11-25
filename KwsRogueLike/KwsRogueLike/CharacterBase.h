#pragma once
#include "mapobject.h"

class CharacterBase
	:public MapObject
{
private:
	int hp, offense, diffense, level=1, moveSpeed;
	bool isMoving = false;
	int frameCount;

protected:
	void SetHp(int hp);
	void HpChanger(int value);
	bool IsMoving()const;
	void SetMoving(bool isMoving);

public:
	CharacterBase(int hp, int offense, int diffense, int moveSpeed, int level);
	~CharacterBase();
	int GetHp();
	int GetLevel();
};

