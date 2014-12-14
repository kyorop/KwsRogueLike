#include <DxLib.h>
#include "Wall.h"
#include "vector2.h"
#include "Screen.h"

int Wall::imageHandle;

void Wall::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}

void Wall::Draw(const Screen& screen)
{
	DrawGraph(GetCoordinate().x - screen.x, GetCoordinate().y - screen.y, imageHandle, true);
}

Wall::Wall(const Vector2& v)
{
	SetCoordinate(v);
	imageHandle = LoadGraph("img/background/wall.png");
}

Wall::~Wall()
{
}
