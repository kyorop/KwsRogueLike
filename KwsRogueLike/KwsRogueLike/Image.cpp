#include <DxLib.h>
#include "Image.h"
#include "IDrawObject.h"
#include "DxLibGraphic.h"


void Image::SetDrawnObject(std::shared_ptr<IDrawObject> drawn)
{
	const int layer = drawn->GetLayer();
	int index;
	if (drawn->IsUsingDivGraph())
		index = divHandleList.size();
	else
		index = handleList.size();

	if (!drawnList.empty())
	{
		const int originalSize = drawnList.size();
		for (auto itr = drawnList.begin(); itr != drawnList.end(); ++itr)
		{
			if ((*itr)->drawnObject->GetLayer() > layer)
			{
				drawnList.insert(itr, std::make_shared<HandleIndexer>(drawn, index));
				break;
			}
		}

		if (originalSize == drawnList.size())
			drawnList.push_back(std::make_shared<HandleIndexer>(drawn, index));
	}
	else
	{
		drawnList.push_back(std::make_shared<HandleIndexer>(drawn, index));
	}
	
	Initialize(drawn);
}

void Image::Draw()
{
	for (auto drawn : drawnList)
	{
		if (drawn->drawnObject->IsUsingDivGraph())
		{
			DxLibWrap::Graphic::DrawDivGraphBy(drawn->drawnObject->GetDivGraphData(), divHandleList[drawn->GetIndex()]);
		}
		else
		{
			DxLibWrap::Graphic::DrawGraphBy(drawn->drawnObject->GetGraphData(), handleList[drawn->GetIndex()]);
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
		DxLibWrap::Graphic::LoadDivGraphBy(drawn->GetDivGraphData(), handle);
		divHandleList.push_back(handle);
	}
	else
	{
		handleList.push_back(DxLibWrap::Graphic::LoadGraphBy(drawn->GetGraphData()));
	}
}