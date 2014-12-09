#pragma once
#include "CharacterBase.h"
#include "scrollingmovement.h"
#include "idrawobject.h"
#include "Vector2.h"

class PlayerBase
	:public CharacterBase, public IDrawObject
{
public:
	DivGraphData GetDivGraphData()const override;

	bool IsUseDivGraph()const override
	{
		return true;
	}

	int GetLayer()const override
	{
		return 0;
	}

	std::string GetImageAddress()const override
	{
		return "img/Enemies/enemy.png";
	}

	int GetX()const override
	{
		return GetCoordinate().x;
	}

	int GetY()const override
	{
		return GetCoordinate().y;
	}

public:
	PlayerBase(int x, int y);
	virtual ~PlayerBase();
	void Draw() override;
	void Move();
	int GetGold();

private:
	ScrollingMovement::Direction drawDirection;
	int charactor[96];
	int gold = 0; //‚Á‚Ä‚¢‚é‹à
};

