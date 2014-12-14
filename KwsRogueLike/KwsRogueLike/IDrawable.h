#pragma once

struct DivGraphData;

class IDrawable
{
public:
	virtual ~IDrawable(){};

	virtual bool IsUsingDivGraph() = 0;
	virtual DivGraphData GetDivData() = 0;
	virtual int GetAnimationHandle() = 0;
	virtual int GetLayer() = 0;
	virtual char* GetImageAddress() = 0;
	virtual bool Removed() = 0;
	virtual void Draw(int handle) = 0;
};

struct DivGraphData
{
	int allNum;
	int xNum;
	int yNum;
	int xSize;
	int ySize;
};