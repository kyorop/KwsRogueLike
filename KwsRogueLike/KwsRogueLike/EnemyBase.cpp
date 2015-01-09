#include "EnemyBase.h"


void EnemyBase::TakeDamage(int damage)
{
	hp -= damage;
}

EnemyBase::EnemyBase(const Vector2& coord, int hp, int offense, int diffense, int moveSpeed, int level)
	:DrawObject(coord)
{
}

EnemyBase::EnemyBase(const Vector2& coord)
	: DrawObject(coord)
{}

EnemyBase::~EnemyBase()
{
}