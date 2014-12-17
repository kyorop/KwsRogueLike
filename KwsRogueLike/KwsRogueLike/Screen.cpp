#include "Screen.h"
#include <DxLib.h>
#include "vector2.h"

Vector2* Screen::coord = new Vector2(0, 0);
const int speed = 4;

Vector2 Screen::GetCoord()
{
	return *coord;
}

void Screen::Update(GameManager* game) const
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