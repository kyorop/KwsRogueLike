#pragma once
#include "IGameProcess.h"

class EnemyManager
	:public IGameProcess
{
public:
	void Update(std::shared_ptr<GameManager> game) const override;
};
