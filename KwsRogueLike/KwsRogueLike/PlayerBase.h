﻿#pragma once
#include <vector>
#include "scrollingmovement.h"
#include "DrawObject.h"
#include "IBattle.h"
#include "generalconstant.h"
#include "vector2.h"

class Meat;

class PlayerBase
	:public DrawObject, public IBattle
{
public:
	Vector2 GetCoordinate() const override;
	Vector2 GetDrawCoord() override;
	int GetHp() override;
	int GetAttack() override;
	void TakeDamage(int damage) override;
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;


	explicit PlayerBase()
		: DrawObject(Vector2(GeneralConstant::playerX, GeneralConstant::playerY))
	{
	}

	virtual ~PlayerBase();
	
	void Update();
	int GetGold();
	int GetLevel();
	void SetItem(std::shared_ptr<Meat>& item);

private:
	ScrollingMovement::Direction drawDirection;
	std::vector<int> handles;
	int gold = 0;
	std::vector<std::shared_ptr<Meat>> equips;
};

