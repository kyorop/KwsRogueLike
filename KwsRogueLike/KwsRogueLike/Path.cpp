#include <DxLib.h>
#include "Path.h"
#include "vector2.h"

int Path::imageHandle;



Path::Path()
{
	imageHandle = LoadGraph("img/background/path.png");
}

Path::~Path()
{
}

void Path::Draw()
{
	DrawGraph(GetCoordinate().x, GetCoordinate().y, imageHandle, true);
}