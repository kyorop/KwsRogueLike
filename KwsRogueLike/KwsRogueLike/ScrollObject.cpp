#include "ScrollObject.h"


ScrollObject::ScrollObject()
{
}


ScrollObject::~ScrollObject()
{
}


void ScrollObject::Scroll(Direction d)
{
	const int moving = 2;

	if (frameCount < 32 / moving && !isMoving && direction != STOP)
	{
		isMoving = true;
		this->direction = direction;
		frameCount = 0;
	}
	else if (frameCount >= 32 / moving && isMoving)
	{
		isMoving = false;
		frameCount = 0;
		this->direction = STOP;
	}

	if (isMoving)
	{
		switch (this->direction)
		{
		case UP:
			AddCoordinate(0, -moving);
			break;
		case UPRIGHT:
			AddCoordinate(moving, -moving);
			break;
		case RIGHT:
			AddCoordinate(moving, 0);
			break;
		case DOWNRIGHT:
			AddCoordinate(moving, moving);
			break;
		case DOWN:
			AddCoordinate(0, moving);
			break;
		case DOWNLEFT:
			AddCoordinate(-moving, moving);
			break;
		case LEFT:
			AddCoordinate(-moving, 0);
			break;
		case UPLEFT:
			AddCoordinate(-moving, -moving);
			break;
		case STOP:
			break;
		}

		frameCount++;
	}
}