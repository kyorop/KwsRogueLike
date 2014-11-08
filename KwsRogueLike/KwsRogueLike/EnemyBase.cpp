#include "EnemyBase.h"
#include "DxLib.h"

EnemyBase::EnemyBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, moveSpeed)
{
	SetCoordinate(0, 0);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
}

EnemyBase::EnemyBase(int x, int y)
	:CharacterBase(0, 0, 0, 0)
{
	SetCoordinate(x, y);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Draw()
{
	Vector2 v = GetCoordinate();
	DrawGraph(v.x, v.y, charactor[3], true);
}