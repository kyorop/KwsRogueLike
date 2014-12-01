#pragma once
#include "mapobject.h"

class Path
	:public MapObject
{
public:
	static int imageHandle;
public:
	explicit Path(const Vector2& v);
	~Path();

	void Draw();
};
