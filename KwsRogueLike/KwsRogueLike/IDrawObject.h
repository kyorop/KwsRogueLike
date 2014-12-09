#pragma once
#include <string>

struct GraphData;
struct DivGraphData;

class IDrawObject
{
public:
	virtual ~IDrawObject(){};

	virtual bool IsUsingDivGraph() const = 0;
	virtual GraphData GetGraphData()const = 0;
	virtual DivGraphData GetDivGraphData()const = 0;
};

struct DivGraphData
{
	int layer;
	std::string address;
	int x;
	int y;
	bool transFlag;

	int allNum;
	int xNum;
	int yNum;
	int xSize;
	int ySize;
	int animationHandle;

	DivGraphData()
		:layer(0),
		address(""),
		x(0),
		y(0),
		transFlag(0),
		allNum(0),
		xNum(0),
		yNum(0),
		xSize(0),
		ySize(0),
		animationHandle(0)
	{}
};

struct GraphData
{
	int layer;
	std::string address;
	int x;
	int y;
	bool transFlag;

	GraphData()
		:layer(0),
		address(nullptr),
		x(0),
		y(0),
		transFlag(0)
	{
	}
};