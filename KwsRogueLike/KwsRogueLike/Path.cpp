#include <DxLib.h>
#include "Path.h"
#include "vector2.h"

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