#include <DxLib.h>
#include "GameManager.h"
#include "Screen.h"
#include "vector2.h"
#include "GeneralConstant.h"
#include "PlayerBase.h"

Vector2* Screen::screenCoord = new Vector2(0, 0);
const int speed = 2;

Vector2 Screen::GetCoord()
{
	return *screenCoord;
}

size_t Screen::Get_player_i()
{
	return (screenCoord->y + GeneralConstant::playerY) / GeneralConstant::img_size_height;
}

size_t Screen::Get_player_j()
{
	return (screenCoord->x + GeneralConstant::playerX) / GeneralConstant::img_size_width;
}

void Screen::Update(GameManager* game)
{	
	if (!isMoving)
	{
		char buf[256];
		GetHitKeyStateAll(buf);
		int input = buf[KEY_INPUT_RIGHT] + buf[KEY_INPUT_LEFT] + buf[KEY_INPUT_DOWN] + buf[KEY_INPUT_UP];
		size_t i = Get_player_i();
		size_t j = Get_player_j();
		size_t i_up = Get_player_i() - 1;
		size_t i_down = Get_player_i() + 1;
		size_t j_right = Get_player_j() + 1;
		size_t j_left = Get_player_j() - 1;
		bool isWall_right = game->GetMapInfo()[i][j_right].isWall;
		bool isWall_left = game->GetMapInfo()[i][j_left].isWall;
		bool isWall_up = game->GetMapInfo()[i_up][j].isWall;
		bool isWall_down = game->GetMapInfo()[i_down][j].isWall;

		if (buf[KEY_INPUT_RIGHT] && !isWall_right)
		{
			isMoving = true;
			direction = RIGHT;
		}
		else if (buf[KEY_INPUT_LEFT] && !isWall_left)
		{
			isMoving = true;
			direction = LEFT;
		}
		else if (buf[KEY_INPUT_DOWN] && !isWall_down)
		{
			isMoving = true;
			direction = DOWN;
		}
		else if (buf[KEY_INPUT_UP] && !isWall_up)
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
			screenCoord->y -= speed;
			break;
		case RIGHT: 
			screenCoord->x += speed;
			break;
		case DOWN: 
			screenCoord->y += speed;
			break;
		case LEFT: 
			screenCoord->x -= speed;
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