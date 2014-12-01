#include "ScrollingMovement.h"
#include <DxLib.h>
#include "vector2.h"

ScrollingMovement::ScrollingMovement()
	:moving(4),
	r_input(false),
	frameCount(0),
	isMoving(false),
	direction(STOP)
{
}

void ScrollingMovement::UpdateDirection(Direction* direction)
{
	if (!isMoving)
	{
		char buf[256];
		GetHitKeyStateAll(buf);
		char input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
		if (buf[KEY_INPUT_R])
		{
			r_input = true;

			if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_RIGHT])
				*direction = DOWNLEFT;
			else if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_LEFT])
				*direction = DOWNRIGHT;
			else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_RIGHT])
				*direction = UPLEFT;
			else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_LEFT])
				*direction = UPRIGHT;
			else
				*direction = STOP;
		}
		else
		{
			if (input < 2)
			{
				if (buf[KEY_INPUT_RIGHT])
					*direction = LEFT;
				else if (buf[KEY_INPUT_LEFT])
					*direction = RIGHT;
				else if (buf[KEY_INPUT_DOWN])
					*direction = UP;
				else if (buf[KEY_INPUT_UP])
					*direction = DOWN;
				else
					*direction = STOP;
			}
			else if (r_input)//一回Rを押してしまえば、話してもななめ移動ができてしまうのを防いている
			{
				*direction = STOP;
				r_input = false;
			}
		}
	}
}

Vector2 ScrollingMovement::GetMoving(Direction direction)
{
	Vector2 movement;

	if (frameCount < (32 / moving) && !isMoving && direction != STOP)
	{
		isMoving = true;
		frameCount = 0;
	}
	else if (isMoving && frameCount >= (32 / moving))
	{
		isMoving = false;
		frameCount = 0;
	}

	if (isMoving)
	{
		switch (direction)
		{
		case UP:
			movement.x = 0;
			movement.y = -moving;
			break;
		case UPRIGHT:
			movement.x = moving;
			movement.y = -moving;
			break;
		case RIGHT:
			movement.x = moving;
			movement.y = 0;
			break;
		case DOWNRIGHT:
			movement.x = moving;
			movement.y = moving;
			break;
		case DOWN:
			movement.x = 0;
			movement.y = moving;
			break;
		case DOWNLEFT:
			movement.x = -moving;
			movement.y = moving;
			break;
		case LEFT:
			movement.x = -moving;
			movement.y = -0;
			break;
		case UPLEFT:
			movement.x = -moving;
			movement.y = -moving;
			break;
		case STOP:
			movement.x = 0;
			movement.y = 0;
			break;
		}
		frameCount++;
	}
	else
	{
		movement.x = 0;
		movement.y = 0;
	}

	return movement;
}

void ScrollingMovement::Scroll(Vector2* coordinate)
{
	UpdateDirection(&direction);
	*coordinate += GetMoving(direction);
}