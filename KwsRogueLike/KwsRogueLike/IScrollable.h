#pragma once

class Vector2;
class IScrollable
{
public:
	virtual void Scroll(const Vector2& v) = 0;
	virtual ~IScrollable(){};
};