#include "PlayerBase.h"
#include "DxLib.h"

PlayerBase::PlayerBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, moveSpeed)
{
	SetCoordinate(0,0);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);

	direction = 0;
}

PlayerBase::PlayerBase(int x, int y)
	:CharacterBase(0, 0, 0, 0)
{
	SetCoordinate(x, y);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
	direction = 0;
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::Draw()
{
	if (!IsMoving())
	{
		if (CheckHitKeyAll())
		{
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
				direction = 1;

			if (CheckHitKey(KEY_INPUT_LEFT) != 0)
				direction = 2;

			if (CheckHitKey(KEY_INPUT_DOWN) != 0)
				direction = 0;

			if (CheckHitKey(KEY_INPUT_UP) != 0)
				direction = 3;
		}
	}


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
	if (!IsMoving())
	{
		if (buf[KEY_INPUT_R] != 0)
		{
			SetMoving(true);
			if ((buf[KEY_INPUT_UP] != 0) && (buf[KEY_INPUT_RIGHT] != 0))
				SetDirection(UPRIGHT);

			else if ((buf[KEY_INPUT_UP] != 0) && (buf[KEY_INPUT_LEFT] != 0))
				SetDirection(UPLEFT);

			else if ((buf[KEY_INPUT_DOWN] != 0) && (buf[KEY_INPUT_RIGHT] != 0))
				SetDirection(DOWNRIGHT);

			else if ((buf[KEY_INPUT_DOWN] != 0) && (buf[KEY_INPUT_LEFT] != 0))
				SetDirection(DOWNLEFT);
			else
				SetMoving(false);
		}
		else
		{
			SetMoving(true);
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
				SetDirection(RIGHT);

			else if (CheckHitKey(KEY_INPUT_LEFT) != 0)
				SetDirection(LEFT);

			else if (CheckHitKey(KEY_INPUT_DOWN) != 0)
				SetDirection(DOWN);

			else if (CheckHitKey(KEY_INPUT_UP) != 0)
				SetDirection(UP);
			else
				SetMoving(false);
		}
	}
	else
		Moving();
}