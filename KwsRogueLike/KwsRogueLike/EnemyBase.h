#pragma once
#include "CharacterBase.h"
#include "IDrawable.h"

class PlayerBase;
class EnemyBase
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

	EnemyBase(int x, int y, int hp, int offense, int diffense, int moveSpeed,int level);
	~EnemyBase();

	void SetCharacter(PlayerBase* player);

private:
	PlayerBase* player;
	bool playerMoved;
};