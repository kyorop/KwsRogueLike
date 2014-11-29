#include "Map.h"
#include "MysteryDungeonMaker.h"
#include "GeneralConstant.h"
#include "Dxlib.h"
#include "MapObject.h"
#include "floor.h"
#include "vector2.h"
#include "wall.h"
#include "floor.h"
#include "path.h"

using namespace GeneralConstant;
using std::vector;
using std::shared_ptr;

Map::Map()
	:isMoving(false),
	r_input(false),
	direction(MapObject::STOP),
	frameCount(0)
{
	floor = 1;
}

void Map::UpdateDirection(MapObject::Direction* direction)
{
	//if (!isMoving)
	{
		char buf[256];
		GetHitKeyStateAll(buf);
		char input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
		if (buf[KEY_INPUT_R])
		{
			r_input = true;

			if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_RIGHT])
				*direction = MapObject::DOWNLEFT;
			else if (buf[KEY_INPUT_UP] && buf[KEY_INPUT_LEFT])
				*direction = MapObject::DOWNRIGHT;
			else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_RIGHT])
				*direction = MapObject::UPLEFT;
			else if (buf[KEY_INPUT_DOWN] && buf[KEY_INPUT_LEFT])
				*direction = MapObject::UPRIGHT;
			else
				*direction = MapObject::STOP;
		}
		else
		{
			if (input < 2)
			{
				if (buf[KEY_INPUT_RIGHT])
					*direction = MapObject::LEFT;
				else if (buf[KEY_INPUT_LEFT])
					*direction = MapObject::RIGHT;
				else if (buf[KEY_INPUT_DOWN])
					*direction = MapObject::UP;
				else if (buf[KEY_INPUT_UP])
					*direction = MapObject::DOWN;
				else
					*direction = MapObject::STOP;
			}
			else if (r_input)//ˆê‰ñR‚ð‰Ÿ‚µ‚Ä‚µ‚Ü‚¦‚ÎA˜b‚µ‚Ä‚à‚È‚È‚ßˆÚ“®‚ª‚Å‚«‚Ä‚µ‚Ü‚¤‚Ì‚ð–h‚¢‚Ä‚¢‚é
			{
				*direction = MapObject::STOP;
				r_input = false;
			}
		}
	}
}

void Map::GetMoving(Vector2* movement, const MapObject::Direction direction)
{
	const int moving = 4;

	if (frameCount < (32 / moving) && !isMoving && direction != MapObject::STOP)
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
		case MapObject::UP:
			movement->x = 0;
			movement->y = -moving;
			break;
		case MapObject::UPRIGHT:
			movement->x = moving;
			movement->y = -moving;
			break;
		case MapObject::RIGHT:
			movement->x = moving;
			movement->y = 0;
			break;
		case MapObject::DOWNRIGHT:
			movement->x = moving;
			movement->y = moving;
			break;
		case MapObject::DOWN:
			movement->x = 0;
			movement->y = moving;
			break;
		case MapObject::DOWNLEFT:
			movement->x = -moving;
			movement->y = moving;
			break;
		case MapObject::LEFT:
			movement->x = -moving;
			movement->y = -0;
			break;
		case MapObject::UPLEFT:
			movement->x = -moving;
			movement->y = -moving;
			break;
		case MapObject::STOP:
			movement->x = 0;
			movement->y = 0;
			break;
		}
		frameCount++;
	}
	else
	{
		movement->x = 0;
		movement->y = 0;
	}
}

void Map::CreateMap()
{
	MysteryDungeonMaker dungeonMaker(mapWidth, mapHeight, sectionWidth, sectionHeight);
	dungeonMaker.SetRoomNum(199);
	auto tempMap = dungeonMaker.CreateDungeon();
	for (int i = 0; i < entireHeight; i++)
	{
		map.push_back(vector<shared_ptr<MapObject>>());
		for (int j = 0; j < entireWidth; j++)
		{
			switch (tempMap[i][j])
			{
			case MysteryDungeonMaker::WALL:
				map[i].push_back(std::make_shared<Wall>(Vector2(i*img_size_height, j*img_size_width)));
				break;
			case MysteryDungeonMaker::FLOOR:
				map[i].push_back(std::make_shared<Floor>(Vector2(i*img_size_height, j*img_size_width)));
				break;
			case MysteryDungeonMaker::PATH:
				map[i].push_back(std::make_shared<Path>(Vector2(i*img_size_height, j*img_size_width)));
				break;
			case MysteryDungeonMaker::UNBRAKABLEWALL: break;
			case MysteryDungeonMaker::STAIR: break;
			default: break;
			}
		}
	}
}

Map::~Map()
{
}

int Map::GetFloor()
{
	return floor;
}

void Map::Move()
{
	if (!isMoving)
		UpdateDirection(&direction);
	Vector2 movement(0,0);
	GetMoving(&movement, direction);

	//if (isMoving)
	{
		for (int i = 0; i < entireHeight; i++)
		{
			for (int j = 0; j < entireWidth; j++)
			{
				map[i][j]->Scroll(movement);
			}
		}
	}

}

bool Map::IsMovable()
{
	return true;
}

void Map::Draw()
{
	for (int i=0; i < entireHeight; i++)
	{
		for (int j=0; j < entireWidth; j++)
		{
			map[i][j]->Draw();
		}
	}
}