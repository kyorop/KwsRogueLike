#include "PlayerBase.h"
#include "DxLib.h"

PlayerBase::PlayerBase()
{
}


PlayerBase::~PlayerBase()
{
}

void PlayerBase::Draw()
{
	LoadDivGraph("img/Enemies/enemy.png",96,12,8,32,32,charactor);
	DrawGraph(this->coordinate.x,this->coordinate.y,charactor[0],true);
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[24], true);

	if (CheckHitKey(KEY_INPUT_LEFT) != 0)
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[12], true);

	if (CheckHitKey(KEY_INPUT_UP) != 0)
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[36], true);

	if (CheckHitKey(KEY_INPUT_DOWN) != 0)
		DrawGraph(this->coordinate.x, this->coordinate.y, charactor[0], true);
}

void PlayerBase::Move()
{
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
		this->coordinate.x += 32;

	if (CheckHitKey(KEY_INPUT_LEFT) != 0)
		this->coordinate.x -= 32;

	if (CheckHitKey(KEY_INPUT_UP) != 0)
		this->coordinate.y += 32;
	
	if (CheckHitKey(KEY_INPUT_DOWN) != 0)
		this->coordinate.y -= 32;
	
		


}