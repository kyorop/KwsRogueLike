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
	int allNum;
	int xNum;
	int yNum;
	int xSize;
	int ySize;
	int animationHandle;

	DivGraphData(int all_num, int x_num, int y_num, int x_size, int y_size, int animation_handle)
		: allNum(all_num),
		  xNum(x_num),
		  yNum(y_num),
		  xSize(x_size),
		  ySize(y_size),
		  animationHandle(animation_handle)
	{}
};

struct GraphData
{
	std::string address;
	int x;
	int y;
	bool transFlag;

	GraphData(const std::string& address, int x, int y, bool trans_flag)
		: address(address),
		  x(x),
		  y(y),
		  transFlag(trans_flag)
	{
	}
};