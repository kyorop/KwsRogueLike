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

	void Update(GameScene* game) override;

private:
	size_t Player_i();

	size_t Player_j();

	PlayerDirection DecideDirection(const DungeonData& map);

	bool UpdateCoord(PlayerDirection direction);

	void Move(const DungeonData& dungeonData);

	static std::shared_ptr<Vector2> screenCoord;
	
	bool isMoving = false;
	
	int moveAmount = 32;

	PlayerDirection direction = PlayerDirection::STOP;
};
