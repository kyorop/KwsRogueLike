#include "PlayerBase.h"
#include "DxLib.h"
#include "vector2.h"


GraphData PlayerBase::GetGraphData() const
{
	return graphData;
}

DivGraphData PlayerBase::GetDivGraphData() const
{
	return divData;
}

PlayerBase::PlayerBase(const Vector2& coord)
	:CharacterBase(15, 8, 8, 2, 1),
	graphData("img/Enemies/enemy.png", coord.x, coord.y, true),
	divData(96, 12, 8, 32, 32, 5)
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