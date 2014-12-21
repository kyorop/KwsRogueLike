#include "Screen.h"
#include <DxLib.h>
#include "vector2.h"

Vector2* Screen::coord = new Vector2(0, 0);
const int speed = 2;

Vector2 Screen::GetCoord()
{
	return *coord;
}

void Screen::Update(GameManager* game)
{
	char buf[256];
	GetHitKeyStateAll(buf);
	int input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
	
	if (!isMoving)
	{
		if (buf[KEY_INPUT_RIGHT])
		{
			isMoving = true;
			direction = RIGHT;
		}
	}
	else
	{
		moveAmount -= speed;
		switch (direction)
		{
		case STOP: break;
		case UP: break;
		case RIGHT: 
			coord->x += speed;
			break;
		case DOWN: break;
		case LEFT: break;
		default: break;
		}

		if (moveAmount == 0)
		{
			isMoving = false;
			direction = STOP;
			moveAmount = 32;
		}
	}
//	if ()
//		*coord += Vector2(speed, 0);
//	else if ()
//		*coord += Vector2(-speed, 0);
//	else if ()
//		*coord += Vector2(0, speed);
//	else if ()
//		*coord += Vector2(0, -speed);
}

void Screen::Update()
{
	char buf[256];
	GetHitKeyStateAll(buf);
	if (buf[KEY_INPUT_RIGHT])
		*coord += Vector2(speed, 0);
	else if (buf[KEY_INPUT_LEFT])
		*coord += Vector2(-speed, 0);
	else if (buf[KEY_INPUT_DOWN])
		*coord += Vector2(0, speed);
	else if (buf[KEY_INPUT_UP])
		*coord += Vector2(0, -speed);
}