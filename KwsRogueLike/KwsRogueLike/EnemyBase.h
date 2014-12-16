#pragma once
#include "CharacterBase.h"
#include "IDrawable.h"
#include <vector>

class PlayerBase;
class EnemyBase
	:public CharacterBase, public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
private:
	EnemyBase(int x, int y, int hp, int offense, int diffense, int moveSpeed,int level);
	~EnemyBase();

	void SetCharacter(PlayerBase* player);
	std::vector<int> handles;
	PlayerBase* player;
	bool playerMoved;
};