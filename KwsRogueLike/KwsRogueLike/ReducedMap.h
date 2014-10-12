#pragma once
#include "Vector2.h"

class ReducedMap
{
public:
	bool isRoom;
	Vector2 roomSize;
	Vector2 roomStartPoint;
	Vector2 roomEndPoint;
public:
	ReducedMap();
	~ReducedMap();
};

