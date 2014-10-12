#pragma once
#include "Vector2.h"
#include "IDrawable.h"
class ObjectBase
	:public IDrawable
{
protected:
	Vector2 coordinate;
	int layer;
public:
	ObjectBase();
	~ObjectBase();
};

