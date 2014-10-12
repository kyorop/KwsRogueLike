#pragma once
#include "Vector2.h"
#include "IDrawable.h"
class ObjectBase
	:public IDrawable
{
private:
	Vector2 coordinate;
	int layer;
public:
	ObjectBase();
	~ObjectBase();
};

