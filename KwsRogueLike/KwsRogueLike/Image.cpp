#include "Image.h"
#include "IDrawObject.h"
#include <DxLib.h>


void Image::SetDrawnObject(std::shared_ptr<IDrawObject> drawn)
{
	//本来はここでソート処理をして、そのインデックスを入れる
	drawnList.push_back(std::make_shared<HandleIndexer>(drawn, drawnList.size()));
	Initialize(drawn);
}

void Image::Draw()
{
	for (auto drawn : drawnList)
	{
		if (drawn->drawnObject->IsUsingDivGraph())
		{
			DrawDivGraphBy(drawn->drawnObject->GetDivGraphData(), divHandleList[drawn->GetIndex()]);
		}
		else
		{
			DrawGraphBy(drawn->drawnObject->GetGraphData(), handleList[drawn->GetIndex()]);
		}
	}
}

void Image::Finalize()
{
}

void Image::Initialize(std::shared_ptr<IDrawObject> drawn)
{
	if (drawn->IsUsingDivGraph())
	{
		DivGraphData divData = drawn->GetDivGraphData();
		int *handle = new int[divData.allNum];
		LoadDivGraphBy(drawn->GetDivGraphData(), handle);
		divHandleList.push_back(handle);
	}
	else
	{
		handleList.push_back(LoadGraphBy(drawn->GetGraphData()));
	}
}



int LoadGraphBy(const GraphData& data)
{
	return LoadGraph(data.address.data(), true);
}

void LoadDivGraphBy(const DivGraphData& data, int* handle)
{
	LoadDivGraph(data.address.data(), 
		data.allNum, 
		data.xNum, 
		data.yNum, 
		data.xSize,
		data.ySize,
		handle, true);
}

void DrawDivGraphBy(const DivGraphData& data, int* handles)
{
	DrawGraph(data.x, data.y, handles[data.animationHandle], data.transFlag);
}

void DrawGraphBy(const GraphData& data, int handle)
{
	DrawGraph(data.x, data.y, handle, data.transFlag);
}