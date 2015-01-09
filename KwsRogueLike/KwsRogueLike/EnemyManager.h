#pragma once
#include "GameManager.h"
#include <vector>
#include <memory>

class EnemyBase;

class EnemyManager:public GameManager
{
public:
	void Initialize() override;
	void Update(GameScene* game) override;
	void Finalize() override;
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	
	void Add(const std::shared_ptr<EnemyBase>& enemy);

	EnemyManager();
	~EnemyManager() override;

private:
	std::vector<std::shared_ptr<EnemyBase>> enemies;
};
