#include "Faily.h"
#include "Image.h"
#include <DxLib.h>

void Faily::Update(GameScene* game)
{
	
}

Faily::Faily(const Vector2& coord, int hp, int offense, int diffense, int moveSpeed, int level)
	:EnemyBase(coord, hp, offense, diffense, moveSpeed, level)
{
}

Faily::Faily(const Vector2& coord)
	: EnemyBase(coord)
{
}

void Faily::Load(ImageManager* manager)
{
	handle = manager->LoadGraph("img/enemies/faily.png");
}

void Faily::Draw(ImageManager* manager)
{
	auto coord = GetDrawCoord();
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handle, true);
}