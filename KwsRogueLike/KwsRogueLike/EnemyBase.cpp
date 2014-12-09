#include "EnemyBase.h"
#include "DxLib.h"
#include "vector2.h"



EnemyBase::EnemyBase(int x, int y, int hp, int offense, int diffense, int movespeed, int level)
	:CharacterBase(hp,offense,diffense,movespeed,level),
	divData("img/Enemies/enemy.png", 96, 12, 8, 32, 32),
	playerMoved(false)
{
	SetCoordinate(x, y);
	divData.x = x;
	divData.y = y;
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::SetCharacter(PlayerBase* player)
{
	this->player = player;
}
