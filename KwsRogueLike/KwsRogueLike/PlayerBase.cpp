#include "PlayerBase.h"
#include "DxLib.h"

PlayerBase::PlayerBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, moveSpeed)
{
	coordinate.x = 0;
	coordinate.y = 0;
	LoadDivGraph("img/Enemies/enemy.png", 96, 12, 8, 32, 32, charactor);
	
	direction = 0;
}


PlayerBase::~PlayerBase()
{
}

void PlayerBase::Draw()
{
	if (CheckHitKeyAll())
	{
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
			direction = 1;

		if (CheckHitKey(KEY_INPUT_LEFT) != 0)
			direction = 2;

		if (CheckHitKey(KEY_INPUT_DOWN) != 0)
			direction = 0;

		if (CheckHitKey(KEY_INPUT_UP) != 0)
			direction = 3;
	}
	
	switch (direction){
	case 0:
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[0], true);
		break;
	case 1:
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[24], true);
		break;
	case 2:
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[12], true);
		break;
	default:
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[36], true);
		break;
	}
	

}

void PlayerBase::Move()
{
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
		this->coordinate.x += 32;

	if (CheckHitKey(KEY_INPUT_LEFT) != 0)
		this->coordinate.x -= 32;

	if (CheckHitKey(KEY_INPUT_DOWN) != 0)
		this->coordinate.y += 32;
	
	if (CheckHitKey(KEY_INPUT_UP) != 0)
		this->coordinate.y -= 32;
	
		


}