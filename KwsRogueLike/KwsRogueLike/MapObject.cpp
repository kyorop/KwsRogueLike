#include "mapobject.h"
#include "CharacterBase.h"
#include "dxlib.h"
#include "Vector2.h"

MapObject::Direction MapObject::direction = MapObject::STOP;
int MapObject::frameCount;
bool MapObject::isMoving;


void MapObject::Scroll(const Vector2& v)
{
	AddCoordinate(v.x, v.y);
}

MapObject::MapObject()
	:r_input(false)
{
}

MapObject::~MapObject()
{
}

void MapObject::Moving()
{
	const int moving = 4;

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