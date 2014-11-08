#pragma once
#include "ScrollableObject.h"

class CharacterBase
	:public ScrollableObject
{
public:
	enum Direction
	{
		UP, UPRIGHT,RIGHT,DOWNRIGHT, DOWN, DOWNLEFT,LEFT,UPLEFT,
	};
private:
	int hp, offense, diffense, level=1, moveSpeed;
	Direction direction;
	bool isMoving;

protected:
	int frameCount;
	void Moving();
	void GetHp(int hp);
	void Damage(int damage);
	void HpChanger(int value);
	Direction GetDirection()const;
	bool IsMoving()const;
	void SetMoving(bool isMoving);
	void SetDirection(Direction direction);

public:
	CharacterBase(int hp, int offense, int diffense, int moveSpeed);
	CharacterBase(int hp, int offense, int diffense, int moveSpeed, int level);
	~CharacterBase();
};

