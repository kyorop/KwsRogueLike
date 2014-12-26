#include <DxLib.h>
#include "Wall.h"
#include "vector2.h"
#include "Screen.h"
#include "Image.h"

static int handle;

int Wall::GetLayer()
{
	return 0;
}

void Wall::Load(ImageManager* manager)
{
	handle = manager->LoadGraph("img/background/wall.png");
}

void Wall::Draw(ImageManager* manager)
{
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handle, true);
}

Wall::~Wall()
{
}
