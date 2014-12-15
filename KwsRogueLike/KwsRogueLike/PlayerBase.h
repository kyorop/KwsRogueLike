#pragma once
#include "CharacterBase.h"
#include "scrollingmovement.h"
#include "Vector2.h"
#include "IDrawable.h"

class PlayerBase
	:public CharacterBase, public IDrawable
{
public:
	DivGraphData GetDivData() override;
	bool IsUsingDivGraph() override;
	int GetAnimationHandle() override;
	int GetLayer() override;
	char* GetImageAddress() override;
	bool Removed() override;
	void Draw(int handle) override;
public:

	void Update();

	explicit PlayerBase(const Vector2& coord);
	virtual ~PlayerBase();
	void Move();
	int GetGold();

private:
	ScrollingMovement::Direction drawDirection;
	int gold = 0; //éùÇ¡ÇƒÇ¢ÇÈã‡
};

