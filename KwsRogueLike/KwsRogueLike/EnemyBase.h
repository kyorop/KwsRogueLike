#pragma once
#include "CharacterBase.h"

class PlayerBase;
class EnemyBase
	:public CharacterBase
{
private:
	PlayerBase* player;
	bool playerMoved;
public:
	int charactor[96];
	EnemyBase(int hp, int offense, int diffense, int moveSpeed);
	EnemyBase(int x, int y);
	~EnemyBase();

	void Draw()override;
	void SetCharacter(PlayerBase* player);
};