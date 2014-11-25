#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"


PlayerBase::PlayerBase(int x, int y)
	:CharacterBase(15, 8, 8, 2, 1)
{
	SetCoordinate(x, y);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
	drawDirection = STOP;
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::Draw()
{
	Vector2 coordinate = GetCoordinate();
	switch (drawDirection)
	{
	case STOP:
		DrawGraph(coordinate.x, coordinate.y, charactor[0], true);
		break;
	case UP:
		DrawGraph(coordinate.x, coordinate.y, charactor[36], true);
		break;
	case UPRIGHT:
	case DOWNRIGHT:
	case RIGHT:
		DrawGraph(coordinate.x, coordinate.y, charactor[24], true);
		break;
	case DOWN:
		DrawGraph(coordinate.x, coordinate.y, charactor[0], true);
		break;
	case UPLEFT:
	case DOWNLEFT:
	case LEFT:
		DrawGraph(coordinate.x, coordinate.y, charactor[12], true);
		break;
	}
}

void PlayerBase::Move()
{
}

int PlayerBase::GetGold()
{
	return gold;
}