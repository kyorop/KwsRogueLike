#pragma once
#include "Vector2.h"
#include "ObjectBase.h"

class ScrollableObject
	:public ObjectBase
{
public:
	ScrollableObject();
	~ScrollableObject();
	void Scroll(Vector2 v);
};

