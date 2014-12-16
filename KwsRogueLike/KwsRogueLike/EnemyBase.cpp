#include "EnemyBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "MapInfo.h"
#include "Image.h"

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
	Vector2 scoord = manager->SolveDrawCoord(GetCoordinate());
	DrawGraph(scoord.x, scoord.y, handles[0], true);
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
