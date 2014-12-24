#include "Stair.h"
#include "Image.h"
#include <DxLib.h>
#include "Vector2.h"

int Stair::GetLayer()
{
	return 1;
}

void Stair::Load(ImageManager* manager)
{
	handle = manager->LoadGraph("img/stair.png");
}

void Stair::Draw(ImageManager* manager)
{
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handle, true);
}