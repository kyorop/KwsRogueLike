#pragma once
#include <memory>

class GameManager;

class IGameProcess
{
public:
	virtual ~IGameProcess(){}

	virtual void Update(std::shared_ptr<GameManager> game)const = 0;
};