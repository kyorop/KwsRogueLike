#include <DxLib.h>
#include "Image.h"
#include "IDrawable.h"
#include "DxLibGraphic.h"


void Image::SetDrawnObject(std::shared_ptr<IDrawable> drawn)
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
			drawn->drawnObject->Draw(divHandleList[drawn->GetIndex()][drawn->drawnObject->GetAnimationHandle]);
		}
		else
		{
			drawn->drawnObject->Draw(handleList[drawn->GetIndex()]);
		}
	}
}

void Image::Finalize()
{
}

void Image::Initialize(std::shared_ptr<IDrawable> drawn)
{
	if (drawn->IsUsingDivGraph())
	{
		DivGraphData data = drawn->GetDivData();
		int *handle = new int[data.allNum];
		LoadDivGraph(drawn->GetImageAddress(), data.allNum, data.xNum, data.yNum, data.xSize, data.ySize, handle);
		divHandleList.push_back(std::vector<int>(&handle[0], &handle[data.allNum]));
		delete[] handle;
	}
	else
	{
		handleList.push_back(LoadGraph(drawn->GetImageAddress()));
	}
}