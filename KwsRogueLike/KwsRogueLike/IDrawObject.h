#pragma once

class IDrawObject
{
public:
	enum ImageType
	{
		PLAYER,
		SWORD,
	};

	virtual int GetLayer() = 0;
	virtual ImageType GetImageType() = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual int GetAnimationHandle() = 0;

	virtual ~IDrawObject(){};
};
