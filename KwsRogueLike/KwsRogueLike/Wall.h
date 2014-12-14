#pragma once
#include "objectbase.h"

class Screen;
class Wall
	:public ObjectBase
{
public:
	void Draw();
	void Draw(const Screen& screen);
private:
	static int imageHandle;
public:
	explicit Wall(const Vector2&  v);
	~Wall();
};
