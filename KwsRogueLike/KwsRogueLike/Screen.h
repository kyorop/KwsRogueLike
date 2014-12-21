#pragma once
#include "IGameProcess.h"

class Vector2;
class Screen
	:public IGameProcess
{
public:
	static Vector2 GetCoord();

	enum Direction
	{
		STOP,
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};
	explicit Screen()
		: isMoving(false),
		moveAmount(32),
		direction(STOP)
	{}

	void Update(GameManager* game) override;
	void Update();
private:
	static Vector2* coord;
	bool isMoving;
	int moveAmount;
	Direction direction;
};
