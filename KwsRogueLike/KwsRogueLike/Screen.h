#pragma once
#include "IGameProcess.h"
#include "ObjectBase.h"
#include "vector2.h"

class Screen
	:public IGameProcess, private ObjectBase
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
		:ObjectBase(Vector2(0,0)),
		isMoving(false),
		moveAmount(32),
		direction(STOP)
	{}

	~Screen(){};

	void Update(GameManager* game) override;
private:
	static Vector2* coord;
	bool isMoving;
	int moveAmount;
	Direction direction;
};
