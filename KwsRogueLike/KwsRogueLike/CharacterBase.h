#pragma once
#include "ScrollObject.h"
#include "mapobject.h"

class CharacterBase
	:public MapObject
{
public:
private:
	int hp, offense, diffense, level=1, moveSpeed;
	bool isMoving = false;
	int frameCount;

protected:
	void SetHp(int hp);
	void Damage(int damage);
	void HpChanger(int value);
	Direction GetDirection()const;
	bool IsMoving()const;
	void SetMoving(bool isMoving);
	void SetDirection(Direction direction);

public:
	//CharacterBase(int hp, int offense, int diffense, int moveSpeed);
	CharacterBase(int hp, int offense, int diffense, int moveSpeed, int level);
	int GetHp();
	int GetLevel();
	

	~CharacterBase();
};

