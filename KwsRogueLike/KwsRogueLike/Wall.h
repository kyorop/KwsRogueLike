#pragma once
#include "objectbase.h"

class Wall
	:public ObjectBase
{
public:
	void Draw();
private:
	static int imageHandle;
public:
	explicit Wall(const Vector2&  v);
	~Wall();
};
