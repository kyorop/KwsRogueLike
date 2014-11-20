#include "PlayerBase.h"
#include "DxLib.h"

/* 必要ないと思われ
PlayerBase::PlayerBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, moveSpeed)
{
	SetCoordinate(0,0);
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);

	direction = STOP;
}
*/

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
	char buf[256];
	GetHitKeyStateAll(buf);

	Direction direction = drawDirection;

	char input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
	if (buf[KEY_INPUT_R])
	{
		if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_RIGHT])
			direction = UPRIGHT;
		else if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_LEFT])
			direction = UPLEFT;
		else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_RIGHT])
			direction = DOWNRIGHT;
		else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_LEFT])
			direction = DOWNLEFT;
		else
			direction = STOP;

		if (direction != STOP)
			drawDirection = direction;
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

			if (direction != STOP)//止まった時の方向を向いたままにするための処置
				drawDirection = direction;
		}
	}

	Moving(direction);
}