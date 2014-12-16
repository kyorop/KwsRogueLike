#pragma once
#include "IGameProcess.h"

class Vector2;
class Screen
	:public IGameProcess
{
public:
	static Vector2 GetCoord();
	
	void Update(std::shared_ptr<GameManager> game) const override;
	void Update();
private:
	static Vector2* coord;
};
