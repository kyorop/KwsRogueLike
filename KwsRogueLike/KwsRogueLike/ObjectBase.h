#pragma once
#include "Vector2.h"
class ObjectBase
{
private:
	Vector2 coordinate;
	int layer;
public:
	ObjectBase();
	~ObjectBase();
};

