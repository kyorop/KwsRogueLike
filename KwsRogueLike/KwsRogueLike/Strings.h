#pragma once
#include <string>
#include "IDrawable.h"

class PlayerBase;

class Strings :public IDrawable
{
public:
	int GetLayer() override
	{
		return 10;
	}

	void Load(ImageManager* manager) override
	{
	}

	void Draw(ImageManager* manager) override;

	bool IsVisible() override
	{
		return true;
	}

	bool IsDead() override
	{
		return false;
	}

	Strings(int currentFloor, PlayerBase* player);
	//階層とプレイヤーデータを受け取って表示
	void DisplayPlayerData();

private:
	int currentFloor;
	PlayerBase* player;

	std::string s_floor;
	std::string s_hp;
	std::string s_level;
	std::string s_gold;
};

