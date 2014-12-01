#pragma once
#include "objectbase.h"

class Floor
	:public ObjectBase
{
public:
	void Draw();

private:
	static int imageHandle;
public:
	explicit Floor(const Vector2& v);
	~Floor();


};
