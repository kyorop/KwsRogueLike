#include <DxLib.h>
#include "Path.h"
#include "vector2.h"
#include "Screen.h"
#include "Image.h"

int Path::imgHandle;

int Path::GetLayer()
{
	return 0;
}

void Path::Load(ImageManager* manager)
{
	imgHandle = manager->LoadGraph("img/background/path.png");
}

void Path::Draw(ImageManager* manager)
{
	Vector2 disp = GetDrawCoord();
	DrawGraph(disp.x, disp.y, imgHandle, true);
}

Path::Path(const Vector2& v)
{
	SetCoordinate(v);
}

Path::~Path()
{
}