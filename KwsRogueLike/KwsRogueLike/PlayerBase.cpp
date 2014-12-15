#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"

PlayerBase::PlayerBase(const Vector2& coord)
	:CharacterBase(15, 8, 8, 2, 1)
{
	SetCoordinate(coord.x, coord.y);
	drawDirection = ScrollingMovement::STOP;
}

PlayerBase::~PlayerBase()
{
}


void PlayerBase::Move()
{
}

int PlayerBase::GetGold()
{
	return gold;
}

DivGraphData PlayerBase::GetDivData()
{
	return DivGraphData();
}

bool PlayerBase::IsUsingDivGraph()
{
	return true;
}

int PlayerBase::GetAnimationHandle()
{
	return 0;
}

int PlayerBase::GetLayer()
{
	return 0;
}

char* PlayerBase::GetImageAddress()
{
	return "img/Enemies/enemy.png";
}

bool PlayerBase::Removed()
{
	return true;
}

void PlayerBase::Draw(int handle)
{
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