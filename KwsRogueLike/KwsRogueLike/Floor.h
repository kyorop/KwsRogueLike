#pragma once
#include "objectbase.h"

class Screen;

class Floor
	:public ObjectBase
{
public:
	void Draw();
	void Draw(const Screen& screen);
private:
	static int imageHandle;
public:
	explicit Floor(const Vector2& v);
	~Floor();


};
