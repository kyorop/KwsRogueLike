#pragma once

class IAnimationObject
{
public:
	virtual int GetAnimationHandle() = 0;
	virtual ~IAnimationObject(){};
};
