#include "PlayerBase.h"
#include "DxLib.h"

PlayerBase::PlayerBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, moveSpeed)
{
	SetCoordinate(0,0);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);

	direction = STOP;
}

PlayerBase::PlayerBase(int x, int y)
	:CharacterBase(0, 0, 0, 0)
{
	SetCoordinate(x, y);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
	direction = STOP;
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::Draw()
{
//	if (!IsMoving())
//	{
//		if (CheckHitKeyAll())
//		{
//			if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
//				direction = RIGHT;
//
//			if (CheckHitKey(KEY_INPUT_LEFT) != 0)
//				direction = LEFT;
//
//			if (CheckHitKey(KEY_INPUT_DOWN) != 0)
//				direction = DOWN;
//
//			if (CheckHitKey(KEY_INPUT_UP) != 0)
//				direction = UP;
//		}
//	}

	Vector2 coordinate = GetCoordinate();
	switch (direction){
	case 0:
		DrawGraph(coordinate.x, coordinate.y, charactor[0], true);
		break;
	case 1:
		DrawGraph(coordinate.x, coordinate.y, charactor[24], true);
		break;
	case 2:
		DrawGraph(coordinate.x, coordinate.y, charactor[12], true);
		break;
	default:
		DrawGraph(coordinate.x, coordinate.y, charactor[36], true);
		break;
	}
}

void PlayerBase::Move()
{
	char buf[256];
	GetHitKeyStateAll(buf);

	Vector2 coordinate = GetCoordinate();

	char input=0;
	input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];

	if (buf[KEY_INPUT_R])
	{
		if ((buf[KEY_INPUT_UP] != 0) && (buf[KEY_INPUT_RIGHT] != 0))
			direction = UPRIGHT;
		else if ((buf[KEY_INPUT_UP] != 0) && (buf[KEY_INPUT_LEFT] != 0))
			direction = UPLEFT;
		else if ((buf[KEY_INPUT_DOWN] != 0) && (buf[KEY_INPUT_RIGHT] != 0))
			direction = DOWNRIGHT;
		else if ((buf[KEY_INPUT_DOWN] != 0) && (buf[KEY_INPUT_LEFT] != 0))
			direction = DOWNLEFT;
		else
			direction = STOP;
	}
	else
	{
		if (input < 2)
		{
			if (buf[KEY_INPUT_RIGHT])
				direction = RIGHT;
			else if (buf[KEY_INPUT_LEFT])
				direction = LEFT;
			else if (buf[KEY_INPUT_DOWN])
				direction = DOWN;
			else if (buf[KEY_INPUT_UP])
				direction = UP;
			else
				direction = STOP;
		}
	}

	Moving(direction);
}