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
	charactor = LoadGraph("img/BrownFloor.png");
	DrawGraph(0,0,charactor,true);
}