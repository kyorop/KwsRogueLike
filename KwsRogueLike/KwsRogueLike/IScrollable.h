#pragma once

class IScrollable
{
public:
	virtual void Scroll() = 0;
	virtual ~IScrollable(){};
};