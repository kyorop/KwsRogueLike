#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"
#include "Image.h"
#include "Screen.h"
#include "GeneralConstant.h"
#include "Meat.h"

PlayerBase::PlayerBase()
{
	drawDirection = ScrollingMovement::STOP;
	SetCoordinate(Vector2(GeneralConstant::playerX, GeneralConstant::playerY));
}

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
	return 1;
}

void PlayerBase::Load(ImageManager* manager)
{
	handles = manager->LoadDivGraph("img/Enemies/enemy.png", 15, 12, 8, 32, 32);
}

void PlayerBase::Draw(ImageManager* manager)
{
	DrawGraph(GetDrawCoord().x, GetDrawCoord().y, handles[0], true);

	if (!equips.empty())
	{
		DrawFormatString(0, 100, GetColor(255, 0, 0), equips[0]->GetExplanation().data());
	}
}

void PlayerBase::Update()
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
//		divData.animationHandle = 17;	
	}
	if (Key[KEY_INPUT_RIGHT] != 0)
	{
//		divData.animationHandle = 29;
	}
	if (Key[KEY_INPUT_UP] != 0)
	{
//		divData.animationHandle = 41;
	}
	if (Key[KEY_INPUT_DOWN] != 0)
	{
//		divData.animationHandle = 5;
	}
}