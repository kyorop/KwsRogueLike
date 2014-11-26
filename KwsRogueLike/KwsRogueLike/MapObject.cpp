#include "mapobject.h"
#include "CharacterBase.h"
#include "dxlib.h"
#include "Vector2.h"


MapObject::MapObject()
	:direction(STOP),
	frameCount(0),
	isMoving(false),
	r_input(false)
{
}

MapObject::~MapObject()
{
}

void MapObject::Moving()
{
	const int moving = 2;

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
	if (!isMoving)
	{
		char buf[256];
		GetHitKeyStateAll(buf);
		char input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
		if (buf[KEY_INPUT_R])
		{
			r_input = true;

			if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_RIGHT])
				direction = DOWNLEFT;
			else if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_LEFT])
				direction = DOWNRIGHT;
			else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_RIGHT])
				direction = UPLEFT;
			else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_LEFT])
				direction = UPRIGHT;
			else
				direction = STOP;
		}
		else
		{
			if (input < 2)
			{
				if (buf[KEY_INPUT_RIGHT])
					direction = LEFT;
				else if (buf[KEY_INPUT_LEFT])
					direction = RIGHT;
				else if (buf[KEY_INPUT_DOWN])
					direction = UP;
				else if (buf[KEY_INPUT_UP])
					direction = DOWN;
				else
					direction = STOP;
			}
			else if (r_input)//ˆê‰ñR‚ð‰Ÿ‚µ‚Ä‚µ‚Ü‚¦‚ÎA˜b‚µ‚Ä‚à‚È‚È‚ßˆÚ“®‚ª‚Å‚«‚Ä‚µ‚Ü‚¤‚Ì‚ð–h‚¢‚Ä‚¢‚é
			{
				direction = STOP;
				r_input = false;
			}
		}
	}

	Moving();
}