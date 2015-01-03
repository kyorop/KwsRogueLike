#pragma once
#include <memory>

class GameManager;

class GameManagerFactory
{
public:
	virtual ~GameManagerFactory(){}
	virtual std::shared_ptr<GameManager> Create()=0;
};
