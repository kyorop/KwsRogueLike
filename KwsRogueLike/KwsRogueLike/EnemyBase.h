#pragma once
#include "IDrawable.h"
#include <vector>
#include "ObjectBase.h"
#include "IBattle.h"

class PlayerBase;
class EnemyBase
	:public ObjectBase, public IDrawable,public IBattle
{
public:
	int GetHp() override;
	int GetAttack() override;
	void TakeDamage(int damage) override;
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
private:
	EnemyBase(int x, int y, int hp, int offense, int diffense, int moveSpeed,int level);
	~EnemyBase();

	std::vector<int> handles;
	PlayerBase* player;
	bool playerMoved;
};