#pragma once
#include "Vector2.h"
#include "ObjectBase.h"

class ScrollObject
	:public ObjectBase
{
public:
	enum Direction
	{
		STOP = -1, UP, UPRIGHT, RIGHT, DOWNRIGHT, DOWN, DOWNLEFT, LEFT, UPLEFT,
	};
private:
	int frameCount;
	bool isMoving;
	Direction direction;
public:
	ScrollObject();
	~ScrollObject();
	virtual void Scroll(Direction d);
};

