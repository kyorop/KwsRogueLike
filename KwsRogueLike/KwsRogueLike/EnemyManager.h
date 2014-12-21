#pragma once
#include "IGameProcess.h"

class EnemyManager
	:public IGameProcess
{
public:
	void Update(GameManager* game) override;
};
