#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"


GraphData PlayerBase::GetGraphData() const
{
	return IDrawObject::GetGraphData();
}

DivGraphData PlayerBase::GetDivGraphData() const
{
	return divData;
}

PlayerBase::PlayerBase(const Vector2& coord)
	:CharacterBase(15, 8, 8, 2, 1)
{
	SetCoordinate(coord.x, coord.y);
	drawDirection = ScrollingMovement::STOP;

	divData.x = coord.x;
	divData.y = coord.y;
	divData.address = "img/Enemies/enemy.png";
	divData.transFlag = true;
	
	divData.allNum = 96;
	divData.xNum = 12;
	divData.yNum = 8;
	divData.xSize = 32;
	divData.ySize = 32;
	divData.animationHandle = 5;
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