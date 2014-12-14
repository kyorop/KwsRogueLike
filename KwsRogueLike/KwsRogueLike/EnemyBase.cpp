#include "EnemyBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "MapInfo.h"

EnemyBase::EnemyBase(int x, int y, int hp, int offense, int diffense, int movespeed, int level)
	:CharacterBase(hp,offense,diffense,movespeed,level),
	graphData("img/Enemies/enemy.png",x,y,true),
	divData(96, 12, 8, 32, 32,0),
	playerMoved(false)
{
	SetCoordinate(x, y);
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::SetCharacter(PlayerBase* player)
{
	this->player = player;
}
