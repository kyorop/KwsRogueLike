#pragma once
#include "mapobject.h"

class Path
	:public MapObject
{
public:
	static int imageHandle;
public:
	Path();
	~Path();

	void Draw() override;
};
