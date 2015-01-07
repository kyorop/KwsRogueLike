#include "EnemyBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "Image.h"

int EnemyBase::GetHp()
{
	return 50;
}

int EnemyBase::GetAttack()
{
	return 10;
}

void EnemyBase::TakeDamage(int damage)
{
}

int EnemyBase::GetLayer()
{
	return 0;
}

void EnemyBase::Load(ImageManager* manager)
{
	handles = manager->LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32);
}

void EnemyBase::Draw(ImageManager* manager)
{
	Vector2 scoord = GetDrawCoord();
	DrawGraph(scoord.x, scoord.y, handles[0], true);
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