#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"

PlayerBase::PlayerBase(const Vector2& coord)
	:CharacterBase(15, 8, 8, 2, 1),
	graphData("img/Enemies/enemy.png", coord.x, coord.y, true),
	divData(96, 12, 8, 32, 32, 5)
{
	SetCoordinate(coord.x, coord.y);
	drawDirection = ScrollingMovement::STOP;
	// "img/Enemies/enemy.png";
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