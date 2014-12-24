#include "GameManager.h"
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
		else if (buf[KEY_INPUT_LEFT])
		{
			isMoving = true;
			direction = LEFT;
		}
		else if (buf[KEY_INPUT_DOWN])
		{
			isMoving = true;
			direction = DOWN;
		}
		else if (buf[KEY_INPUT_UP])
		{
			isMoving = true;
			direction = UP;
		}
	}
	else
	{
		moveAmount -= speed;
		switch (direction)
		{
		case STOP: break;
		case UP: 
			coord->y -= speed;
			break;
		case RIGHT: 
			coord->x += speed;
			break;
		case DOWN: 
			coord->y += speed;
			break;
		case LEFT: 
			coord->x -= speed;
			break;
		default: break;
		}

		if (moveAmount == 0)
		{
			isMoving = false;
			direction = STOP;
			moveAmount = 32;
		}
	}
}