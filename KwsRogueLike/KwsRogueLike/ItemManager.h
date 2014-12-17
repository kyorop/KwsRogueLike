#pragma once
#include "IGameProcess.h"

class ItemManager
	:public IGameProcess
{
public:
	void Update(GameManager* game) const override;
private:
};
