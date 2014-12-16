#pragma once
#include "CharacterBase.h"
#include "scrollingmovement.h"
#include "Vector2.h"
#include "IDrawable.h"
#include <vector>

class PlayerBase
	:public CharacterBase, public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	

	void Update();

	explicit PlayerBase(const Vector2& coord);
	virtual ~PlayerBase();
	void Move();
	int GetGold();

private:
	ScrollingMovement::Direction drawDirection;
	std::vector<int> handles;
	int gold = 0;
};

