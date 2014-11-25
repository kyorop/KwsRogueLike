#include <DxLib.h>
#include "Wall.h"
#include "vector2.h"


int Wall::imageHandle;

void Wall::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}

Wall::Wall()
{
	imageHandle = LoadGraph("img/background/wall.png");
}

Wall::~Wall()
{
}
