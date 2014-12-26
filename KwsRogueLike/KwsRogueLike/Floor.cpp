#include <DxLib.h>
#include "Floor.h"
#include "vector2.h"
#include "Image.h"

static int handle;

int Floor::GetLayer()
{
	return 0;
}

void Floor::Load(ImageManager* manager)
{
	handle = manager->LoadGraph("img/background/floor.png");
}

void Floor::Draw(ImageManager* manager)
{
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handle, true);
}

Floor::~Floor()
{
}