﻿#pragma once
#include "mapobject.h"

class Wall
	:public MapObject
{
public:
	void Draw();
private:
	static int imageHandle;
public:
	explicit Wall(const Vector2&  v);
	~Wall();
};
