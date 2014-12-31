#pragma once
#include "IGameProcess.h"
#include "ObjectBase.h"

class DungeonData;
enum class PlayerDirection
{
	STOP,
	UP,
	RIGHT,
	DOWN,
	LEFT,
};

class Screen
	:public IGameProcess
{
public:
	void Initialize() override;
	void Finalize() override;
	static Vector2 GetCoord();

	explicit Screen()
		:isMoving(false),
		moveAmount(32),
		direction(PlayerDirection::STOP)
	{
	}

	void Update(GameManager* game) override;
	void Update(const DungeonData& map);
private:
	static Vector2* screenCoord;
	
	bool isMoving;
	
	int moveAmount;

	PlayerDirection direction;

	size_t Player_i();

	size_t Player_j();

	PlayerDirection DecideDirection(const DungeonData& map);

	bool Move4Direction(PlayerDirection direction);
};
