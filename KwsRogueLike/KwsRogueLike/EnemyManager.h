#pragma once
#include "IGameProcess.h"

class EnemyManager
	:public IGameProcess
{
public:
	void Initialize() override;
	void Update(GameScene* game) override;
	void Finalize() override;
};
