#pragma once
#include "IGameProcess.h"

class EnemyManager
	:public IGameProcess
{
public:
	void Initialize() override;
	void Update(GameManager* game) override;
	void Finalize() override;
};
