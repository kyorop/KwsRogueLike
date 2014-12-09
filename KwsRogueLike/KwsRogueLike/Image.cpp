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
		if (drawn->drawnObject->IsUseDivGraph())
		{
			DrawDivGraphBy(*drawn->drawnObject, divHandleList[drawn->GetIndex()]);
		}
		else
		{
			DrawGraphBy(*drawn->drawnObject, handleList[drawn->GetIndex()]);
		}
	}
}

void Image::Finalize()
{
}

void Image::Initialize(std::shared_ptr<IDrawObject> drawn)
{
	if (drawn->IsUseDivGraph())
	{
		DivGraphData divData = drawn->GetDivGraphData();
		int *handle = new int[divData.allNum];
		LoadDivGraphBy(*drawn, divData, handle);
		divHandleList.push_back(handle);
	}
	else
	{
		handleList.push_back(LoadGraphBy(*drawn));
	}
}



int LoadGraphBy(const IDrawObject& data)
{
	return LoadGraph(data.GetImageAddress().data(), true);
}

void LoadDivGraphBy(const IDrawObject& data, const DivGraphData& divGraphData, int* handle)
{
	LoadDivGraph(data.GetImageAddress().data(), 
		divGraphData.allNum, 
		divGraphData.xNum, 
		divGraphData.yNum, 
		divGraphData.xSize,
		divGraphData.ySize,
		handle, true);
}

void DrawDivGraphBy(const IDrawObject& data, int* handles)
{
	DrawGraph(data.GetX(), data.GetY(), handles[data.GetDivGraphData().animationHandle], true);
}

void DrawGraphBy(const IDrawObject& data, int handle)
{
	DrawGraph(data.GetX(), data.GetY(), handle, true);
}