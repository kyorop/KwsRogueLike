#pragma once
#include "IGameProcess.h"
#include "IImageAcceptor.h"

class GameManager : public IGameProcess, public IImageAcceptor
{
public:
	virtual ~GameManager(){}
};
