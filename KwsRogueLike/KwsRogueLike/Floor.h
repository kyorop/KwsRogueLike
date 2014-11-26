#pragma once
#include "mapobject.h"

class Floor
	:public MapObject
{
public:
	void Draw() override;

private:
	static int imageHandle;
public:
	explicit Floor(const Vector2& v);
	~Floor();


};
