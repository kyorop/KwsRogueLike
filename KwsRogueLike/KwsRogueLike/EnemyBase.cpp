#include "EnemyBase.h"
#include "DxLib.h"

EnemyBase::EnemyBase()
{
}


EnemyBase::~EnemyBase()
{
}

void EnemyBase::Draw()
{
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
	DrawGraph(this->coordinate.x, this->coordinate.y, charactor[0], true);
}
