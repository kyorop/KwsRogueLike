#include "EnemyBase.h"
#include "DxLib.h"

/*
EnemyBase::EnemyBase(int hp, int offense, int diffense, int moveSpeed,int level)
	:CharacterBase(hp, offense, diffense, moveSpeed, level),
	playerMoved(false)
{
	SetCoordinate(0, 0);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
}
*/

EnemyBase::EnemyBase(int x, int y,int hp,int offense,int diffense,int movespeed,int level)
	:CharacterBase(hp,offense,diffense,movespeed,level),
	playerMoved(false)
{
	SetCoordinate(x, y);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
}

EnemyBase::~EnemyBase()
{
	for (int i = 0; i < 96; i++)
	{
		DeleteGraph(charactor[i]);
	}
}

void EnemyBase::Draw()
{
	Vector2 v = GetCoordinate();
	DrawGraph(v.x, v.y, charactor[3], true);
}

void EnemyBase::SetCharacter(PlayerBase* player)
{
	this->player = player;
}
