#pragma once
#include "objectbase.h"

class Screen;

class Path
	:public ObjectBase
{
public:
	static int imageHandle;
public:
	explicit Path(const Vector2& v);
	~Path();

	void Draw();
	void Draw(const Screen& screen);
};
