#include <DxLib.h>
#include "GameScene.h"
#include "Screen.h"
#include "vector2.h"
#include "GeneralConstant.h"
#include "DungeonData.h"

Vector2* Screen::screenCoord = new Vector2(0, 0);
const int speed = 2;

void Screen::Initialize()
{
}

void Screen::Finalize()
{
}

Vector2 Screen::GetCoord()
{
	return *screenCoord;
}

unsigned Screen::Player_i()
{
	return (screenCoord->y + GeneralConstant::playerY) / GeneralConstant::img_size_height;
}

unsigned Screen::Player_j()
{
	return (screenCoord->x + GeneralConstant::playerX) / GeneralConstant::img_size_width;
}

PlayerDirection Screen::DecideDirection(const DungeonData& map)
{
	char buf[256];
	GetHitKeyStateAll(buf);
	size_t i = Player_i();
	size_t j = Player_j();
	size_t i_up = Player_i() - 1;
	size_t i_down = Player_i() + 1;
	size_t j_right = Player_j() + 1;
	size_t j_left = Player_j() - 1;

	if (!buf[KEY_INPUT_LSHIFT])
	{
		if (buf[KEY_INPUT_RIGHT] && !map.IsThis(ObjTypeOnMap::WALL, i, j_right))
			return PlayerDirection::RIGHT;
		if (buf[KEY_INPUT_LEFT] && !map.IsThis(ObjTypeOnMap::WALL, i, j_left))
			return PlayerDirection::LEFT;
		if (buf[KEY_INPUT_DOWN] && !map.IsThis(ObjTypeOnMap::WALL, i_down, j))
			return PlayerDirection::DOWN;
		if (buf[KEY_INPUT_UP] && !map.IsThis(ObjTypeOnMap::WALL, i_up, j))
			return PlayerDirection::UP;
	}
	else
	{
		if (buf[KEY_INPUT_RIGHT])
			return PlayerDirection::RIGHT;
		if (buf[KEY_INPUT_LEFT])
			return PlayerDirection::LEFT;
		if (buf[KEY_INPUT_DOWN])
			return PlayerDirection::DOWN;
		if (buf[KEY_INPUT_UP])
			return PlayerDirection::UP;
	}

	return PlayerDirection::STOP;
}

bool Screen::Move4Direction(PlayerDirection direction)
{
	moveAmount -= speed;
	switch (direction)
	{
	case PlayerDirection::UP:
		screenCoord->y -= speed;
		break;
	case PlayerDirection::RIGHT:
		screenCoord->x += speed;
		break;
	case PlayerDirection::DOWN:
		screenCoord->y += speed;
		break;
	case PlayerDirection::LEFT:
		screenCoord->x -= speed;
		break;
	default:
		break;
	}

	if (moveAmount == 0)
	{
		moveAmount = 32;
		return true;
	}

	return false;
}

void Screen::Update(GameScene* game)
{
	if (!isMoving)
	{
		direction = DecideDirection(game->GetDungeonData());
		if (direction != PlayerDirection::STOP)
			isMoving = true;
	}
	else
	{
		if (Move4Direction(direction))
			isMoving = false;
	}
}