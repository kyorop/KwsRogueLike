#pragma once
#include <string>

struct GraphData;
struct DivGraphData;

class IDrawObject
{
public:
	virtual ~IDrawObject(){};

	virtual bool GetLayer()const = 0;
	virtual bool IsUsingDivGraph() const = 0;
	virtual GraphData GetGraphData()const = 0;
	virtual DivGraphData GetDivGraphData()const = 0;
};

struct DivGraphData
{
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
		:address(""),
		x(0),
		y(0),
		transFlag(false),
		allNum(0),
		xNum(0),
		yNum(0),
		xSize(0),
		ySize(0),
		animationHandle(0)
	{}


	DivGraphData(const std::string& address, int all_num, int x_num, int y_num, int x_size, int y_size)
		: address(address),
		  allNum(all_num),
		  xNum(x_num),
		  yNum(y_num),
		  xSize(x_size),
		  ySize(y_size),
		  x(0),
		  y(0),
		  transFlag(false),
		  animationHandle(0)
	{}
};

struct GraphData
{
	std::string address;
	int x;
	int y;
	bool transFlag;

	GraphData()
		:address(""),
		x(0),
		y(0),
		transFlag(false)
	{
	}

	explicit GraphData(const std::string& address)
		: address(address),
		x(0),
		y(0),
		transFlag(false)
	{
	}
};