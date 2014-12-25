#include "Meat.h"
#include "Image.h"
#include <DxLib.h>
#include "Vector2.h"

int Meat::GetLayer()
{
	return 1;
}

void Meat::Load(ImageManager* manager)
{
	handle = manager->LoadGraph("img/food/meat.png");
}

void Meat::Draw(ImageManager* manager)
{
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handle, true);
}