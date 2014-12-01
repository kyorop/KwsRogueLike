#pragma once
#include "objectbase.h"

class Path
	:public ObjectBase
{
public:
	static int imageHandle;
public:
	explicit Path(const Vector2& v);
	~Path();

	void Draw();
};
