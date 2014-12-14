#pragma once

class IDrawable
{
public:
	virtual int GetLayer() = 0;
	virtual void Draw(int drawX, int drawY, int handle) = 0;
	virtual ~IDrawable(){};
};