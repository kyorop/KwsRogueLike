#include "EnemyBase.h"

EnemyBase::EnemyBase(hp, offense, diffense, moveSpeed)
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
}

EnemyBase::EnemyBase(hp, offense, diffense, moveSpeed, level)
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
	this->level = level;
}


EnemyBase::~EnemyBase()
{
}
