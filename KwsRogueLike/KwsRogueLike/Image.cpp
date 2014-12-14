#include <DxLib.h>
#include "Image.h"
#include "IDrawObject.h"
#include "DxLibGraphic.h"


void ImageManager::Update(std::shared_ptr<GameManager> game) const
{
}

void ImageManager::SetDrawnObject(std::shared_ptr<IDrawObject> drawn)
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

void ImageManager::Draw()
{
	for (auto drawn : drawnList)
	{
		if (drawn->drawnObject->IsUsingDivGraph())
		{
			int handleIndex = drawn->drawnObject->GetDivGraphData().animationHandle;
			DxLibWrap::Graphic::DrawGraphBy(drawn->drawnObject->GetGraphData(), divHandleList[drawn->GetIndex()][handleIndex]);
		}
		else
		{
			DxLibWrap::Graphic::DrawGraphBy(drawn->drawnObject->GetGraphData(), handleList[drawn->GetIndex()]);
		}
	}
}

void ImageManager::Finalize()
{
}

void ImageManager::Initialize(std::shared_ptr<IDrawObject> drawn)
{
	if (drawn->IsUsingDivGraph())
	{
		DivGraphData divData = drawn->GetDivGraphData();
		int *handle = new int[divData.allNum];
		DxLibWrap::Graphic::LoadDivGraphBy(drawn->GetGraphData() ,drawn->GetDivGraphData(), handle);
		std::vector<int> handleArray(&handle[0], &handle[divData.allNum]);
		divHandleList.push_back(handleArray);
		delete[] handle;
	}
	else
	{
		handleList.push_back(DxLibWrap::Graphic::LoadGraphBy(drawn->GetGraphData()));
	}
}