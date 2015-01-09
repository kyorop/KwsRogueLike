#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "Image.h"
#include "Screen.h"
#include "GeneralConstant.h"
#include "Meat.h"

PlayerBase::~PlayerBase()
{
}

int PlayerBase::GetGold()
{
	return gold;
}

int PlayerBase::GetLevel()
{
	return 5;
}

void PlayerBase::SetItem(std::shared_ptr<Meat>& item)
{
	equips.push_back(item);
}

Vector2 PlayerBase::GetCoordinate() const
{
	return Screen::GetCoord() + Vector2(GeneralConstant::playerX, GeneralConstant::playerY);
}

Vector2 PlayerBase::GetDrawCoord()
{
	return Vector2(GeneralConstant::playerX, GeneralConstant::playerY);
}

int PlayerBase::GetHp()
{
	return 50;
}

int PlayerBase::GetAttack()
{
	return 10;
}

void PlayerBase::TakeDamage(int damage)
{
}

int PlayerBase::GetLayer()
{
	return 2;
}

void PlayerBase::Load(ImageManager* manager)
{
	handles = manager->LoadDivGraph("img/Enemies/enemy.png", 12*8, 12, 8, 32, 32);
}

void PlayerBase::Draw(ImageManager* manager)
{
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handles[i_direction], true);
}

void PlayerBase::UpdateImgDirection()
{
	int Key[256];
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++){
		if (tmpKey[i] != 0){
			Key[i]++;
		}
		else {
			Key[i] = 0;
		}
	}

	if (Key[KEY_INPUT_LEFT] != 0)
	{
		i_direction = 6 + 12 * 1;
	}
	if (Key[KEY_INPUT_RIGHT] != 0)
	{
		i_direction = 6 + 12 * 2;
	}
	if (Key[KEY_INPUT_UP] != 0)
	{
		i_direction = 6 + 12 * 3;
	}
	if (Key[KEY_INPUT_DOWN] != 0)
	{
		i_direction = 6 + 12 * 0;
	}
}

void PlayerBase::Update()
{
	UpdateImgDirection();
}