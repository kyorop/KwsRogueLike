#pragma once
#include <memory>

class GameManager;

class IGameProcess
{
public:
	virtual ~IGameProcess(){}

	virtual void Update(GameManager* game) = 0;
};