#include <DxLib.h>
#include "Floor.h"
#include "vector2.h"

int Floor::imageHandle;

void Floor::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}

Floor::Floor()
{
	imageHandle = LoadGraph("img/background/floor.png");;
}

Floor::~Floor()
{
}