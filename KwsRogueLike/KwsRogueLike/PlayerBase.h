#pragma once
#include "CharacterBase.h"
#include "scrollingmovement.h"
#include "idrawobject.h"
#include "Vector2.h"

class PlayerBase
	:public CharacterBase, public IDrawObject
{
public:
	bool GetLayer() const override
	{
		return 0;
	}

	void Update();

	GraphData GetGraphData() const override;
	DivGraphData GetDivGraphData()const override;
	bool IsUsingDivGraph() const override
	{
		return true;
	}

	explicit PlayerBase(const Vector2& coord);
	virtual ~PlayerBase();
	void Move();
	int GetGold();

private:
	ScrollingMovement::Direction drawDirection;
	int gold = 0; //�����Ă����
	DivGraphData divData;
};

