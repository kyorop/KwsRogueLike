#pragma once
#include "EnemyBase.h"

class GameScene;
class Faily:public EnemyBase
{
public:
	void Initialize() override
	{
	}

	void Update(GameScene* game) override;

	void Finalize() override
	{
	}

	Faily(const Vector2& coord, int hp, int offense, int diffense, int moveSpeed, int level);
	explicit Faily(const Vector2& coord);

	bool GetDrawFlag() override
	{
		return true;
	}

	bool IsDead() override
	{
		return false;
	}

	int GetHp() override
	{
		return 3;
	}

	int GetAttack() override
	{
		return 5;
	}

	void TakeDamage(int damage) override
	{
	}

	int GetLayer() override
	{
		return 3;
	}

	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	
private:
	int handle;
};
