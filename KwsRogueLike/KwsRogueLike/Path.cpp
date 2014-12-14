#include <DxLib.h>
#include "Path.h"
#include "vector2.h"
#include "Screen.h"

int Path::imageHandle;

Path::Path(const Vector2& v)
{
	SetCoordinate(v);
	imageHandle = LoadGraph("img/background/path.png");
}

Path::~Path()
{
}

void Path::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}

void Path::Draw(const Screen& screen)
{
	DrawGraph(GetCoordinate().x - screen.x, GetCoordinate().y - screen.y, imageHandle, true);
}