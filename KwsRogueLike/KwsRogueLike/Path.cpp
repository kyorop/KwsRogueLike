#include <DxLib.h>
#include "Path.h"
#include "vector2.h"
#include "Screen.h"
#include "Image.h"

int Path::imgHandle;
//static int handle;

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
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, imgHandle, true);
}

Path::Path(const Vector2& v)
{
	SetCoordinate(v);
}

Path::~Path()
{
}