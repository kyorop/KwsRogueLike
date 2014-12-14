#pragma once


class Vector2;

class IItemTaken
{
public:
	virtual ~IItemTaken(){};
	virtual Vector2 GetCoord() = 0;
	virtual bool IsTaken() = 0;
};
