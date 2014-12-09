#pragma once
#include <string>

class IDrawObject
{
public:
	enum ImageType
	{
		PLAYER,
		SWORD,
	};

	virtual ~IDrawObject(){};

	virtual int GetLayer() = 0;
	virtual std::string GetImageAddress() = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual int GetAnimationHandle() = 0;

};
