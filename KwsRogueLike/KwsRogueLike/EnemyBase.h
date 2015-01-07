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

	EnemyBase(const Vector2& coord, int hp, int offense, int diffense, int moveSpeed, int level);
	explicit EnemyBase(const Vector2& coord);
	~EnemyBase() override;

private:
	std::vector<int> handles;
	PlayerBase* player;
	bool playerMoved;
};