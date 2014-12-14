#pragma once
#include "IGameProcess.h"

class Screen
	:public IGameProcess
{
public:
	void Update(std::shared_ptr<GameManager> game) const override;
	void Update();

	Screen()
		: x(0),
		  y(0)
	{
	}

public:
	int x;
	int y;
};
