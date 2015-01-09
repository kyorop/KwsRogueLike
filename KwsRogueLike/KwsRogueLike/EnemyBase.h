#pragma once
#include "DrawObject.h"
#include "IBattle.h"
#include "IGameProcess.h"

class Vector2;

class EnemyBase
	:public DrawObject, public IBattle, public IGameProcess
{
public:
	int GetHp() override
	{
		return hp;
	}

	int GetAttack() override
	{
		return attack;
	}

	int GetLayer() override
	{
		return 3;
	}

	void TakeDamage(int damage) override;

	EnemyBase(const Vector2& coord, int hp, int offense, int diffense, int moveSpeed, int level);
	explicit EnemyBase(const Vector2& coord);
	~EnemyBase() override;

private:
	int hp;
	int attack;
	int diffence;
};