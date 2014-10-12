#include "EnemyBase.h"
#include "DxLib.h"

EnemyBase::EnemyBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, moveSpeed)
{
	coordinate.x = 0;
	coordinate.y = 0;
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
}


EnemyBase::~EnemyBase()
{
}

void EnemyBase::Draw()
{
	
	DrawGraph(this->coordinate.x, this->coordinate.y, charactor[3], true);
}
