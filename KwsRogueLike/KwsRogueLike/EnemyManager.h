#pragma once
#include "GameManager.h"
#include <vector>

class EnemyBase;

class EnemyManager:public GameManager
{
public:
	void Initialize() override;
	void Update(GameScene* game) override;
	void Finalize() override;
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	
	void Add(const EnemyBase& enemy);

	EnemyManager();
	~EnemyManager() override;

private:
	std::vector<EnemyBase> enemies;
};
