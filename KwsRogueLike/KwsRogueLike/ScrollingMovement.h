#pragma once
#include <memory>

class Vector2;
class MapObject;

class ScrollingMovement
{
public:
	ScrollingMovement();
	enum Direction
	{
		STOP = -1,
		UP,
		UPRIGHT,
		RIGHT,
		DOWNRIGHT,
		DOWN,
		DOWNLEFT,
		LEFT,
		UPLEFT,
	};
private:
	std::shared_ptr<Vector2> movement;
	bool r_input;
	int frameCount;
	const int moving;
	bool isMoving;
	Direction direction;

private:
	void UpdateDirection(Direction* direction);
	Vector2 GetMoving(Direction direction);

public:
	void Scroll(Vector2* coordinate);
};
