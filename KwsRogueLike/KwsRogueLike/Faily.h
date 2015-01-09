#pragma once
#include "EnemyBase.h"

class GameScene;
class Faily:public EnemyBase
{
public:
	void Initialize() override;

	void Update(GameScene* game) override;

	void Finalize() override;

	Faily(const Vector2& coord, int hp, int offense, int diffense, int moveSpeed, int level);

	explicit Faily(const Vector2& coord);

	void Load(ImageManager* manager) override;

	void Draw(ImageManager* manager) override;
	
private:
	int handle;
};
