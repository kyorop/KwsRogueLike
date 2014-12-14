#pragma once
#include "CharacterBase.h"
#include "IDrawObject.h"

class PlayerBase;
class EnemyBase
	:public CharacterBase, public IDrawObject
{
public:

	bool GetLayer() const override
	{
		return 1;
	}

	bool IsUsingDivGraph() const override
	{
		return true;
	}

	GraphData GetGraphData() const override
	{
		return graphData;
	}

	DivGraphData GetDivGraphData() const override
	{
		return divData;
	}

	EnemyBase(int x, int y, int hp, int offense, int diffense, int moveSpeed,int level);
	~EnemyBase();

	void SetCharacter(PlayerBase* player);

private:
	GraphData graphData;
	DivGraphData divData;
	PlayerBase* player;
	bool playerMoved;
};