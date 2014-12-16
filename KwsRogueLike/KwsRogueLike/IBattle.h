#pragma once

class IBattle
{
public:
	virtual ~IBattle(){}

	virtual int GetHp() = 0;
	virtual int GetAttack() = 0;
	virtual void TakeDamage(int damage) = 0;
};