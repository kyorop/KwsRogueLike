#include "EnemyBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "MapInfo.h"

DivGraphData EnemyBase::GetDivData()
{
	return DivGraphData();
}

bool EnemyBase::IsUsingDivGraph()
{
	return true;
}

int EnemyBase::GetAnimationHandle()
{
	return 0;
}

int EnemyBase::GetLayer()
{
	return 0;
}

char* EnemyBase::GetImageAddress()
{
	return "img/Enemies/enemy.png";
}

bool EnemyBase::Removed()
{
	return true;
}

void EnemyBase::Draw(int handle)
{
}

EnemyBase::EnemyBase(int x, int y, int hp, int offense, int diffense, int movespeed, int level)
	:CharacterBase(hp,offense,diffense,movespeed,level),
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
