#pragma once
#include <vector>
#include "DrawObject.h"
#include "IBattle.h"
#include "vector2.h"

class PlayerBase;
class EnemyBase
	:public DrawObject, public IBattle
{
public:
	int GetHp() override;
	int GetAttack() override;
	void TakeDamage(int damage) override;
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
private:
	EnemyBase(int x, int y, int hp, int offense, int diffense, int moveSpeed, int level)
		:DrawObject(Vector2(x,y))
	{
	}

	~EnemyBase();

	std::vector<int> handles;
	PlayerBase* player;
	bool playerMoved;
};