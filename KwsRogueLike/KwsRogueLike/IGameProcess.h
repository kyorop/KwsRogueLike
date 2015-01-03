#pragma once

class GameScene;

class IGameProcess
{
public:
	virtual ~IGameProcess(){}

	virtual void Initialize() = 0;
	virtual void Update(GameScene* game) = 0;
	virtual void Finalize() = 0;
};