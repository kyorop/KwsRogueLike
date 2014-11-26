#include <DxLib.h>
#include "Wall.h"
#include "vector2.h"

int Wall::imageHandle;

void Wall::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}

Wall::Wall(const Vector2& v)
{
	SetCoordinate(v);
	imageHandle = LoadGraph("img/background/wall.png");
}

Wall::~Wall()
{
}
