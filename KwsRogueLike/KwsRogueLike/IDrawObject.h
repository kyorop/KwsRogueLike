#pragma once
#include <string>

struct DivGraphData;

class IDrawObject
{
public:
	enum ImageType
	{
		PLAYER,
		SWORD,
	};

	virtual ~IDrawObject(){};

	virtual int GetLayer()const = 0;
	virtual std::string GetImageAddress()const = 0;
	virtual int GetX()const = 0;
	virtual int GetY()const = 0;

	virtual bool IsUseDivGraph()const = 0;
	virtual DivGraphData GetDivGraphData()const = 0;

};

struct DivGraphData
{
	int allNum;
	int xNum;
	int yNum;
	int xSize;
	int ySize;
	int animationHandle;
};