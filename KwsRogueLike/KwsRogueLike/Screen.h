#pragma once
#include "IGameProcess.h"
#include "ObjectBase.h"
#include "vector2.h"

class Screen
	:public IGameProcess
{
public:
	void Initialize() override;
	void Finalize() override;
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
		:isMoving(false),
		moveAmount(32),
		direction(STOP)
	{
	}

	~Screen(){};

	void Update(GameManager* game) override;
	size_t Get_player_i();
	size_t Get_player_j();
private:
	static Vector2* screenCoord;
	bool isMoving;
	int moveAmount;
	Direction direction;
};
