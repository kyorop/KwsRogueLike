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
	Floor();
	~Floor();


};
