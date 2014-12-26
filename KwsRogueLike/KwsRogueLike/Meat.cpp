#include "Meat.h"
#include "Image.h"
#include <DxLib.h>
#include "Vector2.h"
#include "PlayerBase.h"

std::string Meat::GetName()
{
	return "Meat";
}

std::string Meat::GetExplanation()
{
	return "これを食べると体力を回復します";
}

void Meat::GiveEffect(PlayerBase* player)
{
}

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