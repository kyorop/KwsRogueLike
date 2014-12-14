#include "Screen.h"
#include <DxLib.h>

const int speed = 2;

void Screen::Update(std::shared_ptr<GameManager> game) const
{
}

void Screen::Update()
{
	char buf[256];
	GetHitKeyStateAll(buf);
	if (buf[KEY_INPUT_RIGHT])
		x += speed;
	else if (buf[KEY_INPUT_LEFT])
		x -= speed;
	else if (buf[KEY_INPUT_DOWN])
		y += speed;
	else if (buf[KEY_INPUT_UP])
		y -= speed;
}