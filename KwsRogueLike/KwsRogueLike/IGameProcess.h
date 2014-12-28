#pragma once
#include <memory>

class GameManager;

class IGameProcess
{
public:
	virtual ~IGameProcess(){}

	virtual void Initialize() = 0;
	virtual void Update(GameManager* game) = 0;
	virtual void Finalize() = 0;
};