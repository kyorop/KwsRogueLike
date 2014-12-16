#include "EnemyBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "MapInfo.h"
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

EnemyBase::EnemyBase(int x, int y, int hp, int offense, int diffense, int movespeed, int level)
{
	SetCoordinate(x, y);
}

EnemyBase::~EnemyBase()
{
}