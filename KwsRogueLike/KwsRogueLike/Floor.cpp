#include <DxLib.h>
#include "Floor.h"
#include "vector2.h"
#include "Screen.h"

int Floor::imageHandle;

void Floor::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}

void Floor::Draw(const Screen& screen)
{
	DrawGraph(GetCoordinate().x - screen.x, GetCoordinate().y - screen.y, imageHandle, true);;
}

::Floor::Floor(const Vector2& v)
{
	SetCoordinate(v);
	imageHandle = LoadGraph("img/background/floor.png");
}

Floor::~Floor()
{
}