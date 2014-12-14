#pragma once
#include "IGameProcess.h"

class ItemManager
	:public IGameProcess
{
public:
	void Update(std::shared_ptr<GameManager> game) const override;
private:
};
