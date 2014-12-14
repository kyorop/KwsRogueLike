#pragma once
#include "ObjectBase.h"
#include "IDrawObject.h"

class Item
	:public ObjectBase, public IDrawObject
{
public:
	bool GetLayer() const override
	{
		return 0;
	}

	bool IsUsingDivGraph() const override
	{
		return false;
	}

	GraphData GetGraphData() const override
	{
		return *imageData.get();
	}

	DivGraphData GetDivGraphData() const override
	{
		return IDrawObject::GetDivGraphData();
	}

	Item(std::string imageAddress, int x, int y, bool transFlag)
		:imageData(std::make_shared<GraphData>(imageAddress, x, y, transFlag))
	{
		SetCoordinate(x, y);
	}

private:
	std::shared_ptr<GraphData> imageData;
};
