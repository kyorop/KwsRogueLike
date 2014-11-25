#include "mapobject.h"
#include "CharacterBase.h"
#include "dxlib.h"


MapObject::MapObject()
{
}


MapObject::~MapObject()
{
}

void MapObject::Moving()
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

void MapObject::SetMapComponent(MysteryDungeonMaker::MapComponent mapComponent)
{
	mapState = mapComponent;
}

MysteryDungeonMaker::MapComponent MapObject::GetMapComponent()const
{
	return mapState;
}

void MapObject::Scroll()
{
	char buf[256];
	GetHitKeyStateAll(buf);

	Direction direction = this->direction;

	char input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
	if (isMoving)
	{
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
				this->direction = direction;
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

				if (direction != STOP)//Ž~‚Ü‚Á‚½Žž‚Ì•ûŒü‚ðŒü‚¢‚½‚Ü‚Ü‚É‚·‚é‚½‚ß‚Ìˆ’u
					this->direction = direction;
			}
		}
	}
}