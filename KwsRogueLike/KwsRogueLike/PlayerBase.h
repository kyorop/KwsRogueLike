#pragma once
#include <vector>
#include "scrollingmovement.h"
#include "IDrawable.h"
#include "ObjectBase.h"
#include "IBattle.h"

class PlayerBase
	:public ObjectBase,public IDrawable,public IBattle
{
public:
	int GetHp() override;
	int GetAttack() override;
	void TakeDamage(int damage) override;
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	
	explicit PlayerBase(const Vector2& coord);
	virtual ~PlayerBase();
	
	void Update();
	int GetGold();
	int GetLevel();

private:
	ScrollingMovement::Direction drawDirection;
	std::vector<int> handles;
	int gold = 0;
};

