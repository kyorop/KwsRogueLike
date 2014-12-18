#include <DxLib.h>
#include "Image.h"
#include "IDrawable.h"
#include "GameManager.h"
#include "Screen.h"
#include "Vector2.h"

void ImageManager::Update(GameManager* game) const
{
	*screenCoord = game->GetScreen().GetCoord();
}

ImageManager::ImageManager()
	:screenCoord(std::make_shared<Vector2>(0,0))
{
}

void ImageManager::SetDrawnObject(const std::shared_ptr<IDrawable>& drawn)
{
//	const int thisLayer = drawn->GetLayer();
//	bool pushed = false;
//	auto itr_end = drawnList.end();
//	for (auto itr = drawnList.begin(); itr != itr_end; ++itr)
//	{
//		if ((*itr)->GetLayer() >= thisLayer)
//		{
//			drawnList.insert(itr, drawn);
//			pushed = true;
//			break;
//		}
//	}
//
//	if (!pushed)
//		drawnList.push_back(drawn);
	
	drawnList.push_back(drawn);
}

void ImageManager::Initialize()
{
	SortDrawnList(drawnList);

	for (auto drawn : drawnList)
	{
		drawn->Load(this);
	}
}

void ImageManager::Draw()
{
	for (auto drawn : drawnList)
	{
		drawn->Draw(this);
	}
}

void ImageManager::Finalize()
{
	for (auto deleteObj : handleList)
	{
		DeleteGraph(deleteObj);
	}
}

int ImageManager::LoadGraph(const std::string& imgFileAddress)
{
	if(loadedImg.find(imgFileAddress) == loadedImg.end())
	{
		int handle = DxLib::LoadGraph(imgFileAddress.data());
		loadedImg.insert(make_pair(imgFileAddress, handle));
		handleList.push_back(handle);
		return handle;
	}
	return loadedImg[imgFileAddress];
}

std::vector<int> ImageManager::LoadDivGraph(const std::string& imgFileAddress, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	int* handle = new int[allNum];
	DxLib::LoadDivGraph(imgFileAddress.data(), allNum, xNum, yNum, xSize, ySize, handle);
	std::vector<int> vHandle(&handle[0], &handle[allNum]);
	delete[] handle;
	handleList.insert(end(handleList), begin(vHandle), end(vHandle));
	return vHandle;
}

void ImageManager::SortDrawnList(std::vector<std::shared_ptr<IDrawable>>& list)
{
	const size_t originalSize = list.size();
	for (size_t i = 0; i < originalSize; ++i)
	{
		size_t i_parent = i / 2;
		size_t i_child = i;
		while (list[i_parent]->GetLayer() < list[i_child]->GetLayer())
		{
			swap(list[i_parent], list[i]);
			i_child = i_parent;
			i_parent = i_parent / 2;
		}
	}

	size_t bottom = originalSize;
	for (int i = originalSize - 1; i >= 0; --i)
	{
		swap(list[0], list[i]);
		bottom -= 1;
		size_t i_parent = 0;
		size_t i_left = 1;
		size_t i_right = 2;
		size_t i_bigger;

		if (i_right < bottom)
		{
			if (list[i_left]->GetLayer() < list[i_right]->GetLayer())
				i_bigger = i_right;
			else
				i_bigger = i_left;
		}
		else if (i_left < bottom)
		{
			i_bigger = i_left;
		}
		else
			break;

		while (list[i_parent]->GetLayer() < list[i_bigger]->GetLayer())
		{
			swap(list[i_parent], list[i_bigger]);
			i_parent = i_bigger;

			i_left = 2 * i_parent + 1;
			i_right = 2 * i_parent + 2;

			if (i_right < bottom)
			{
				if (list[i_left]->GetLayer() < list[i_right]->GetLayer())
					i_bigger = i_right;
				else
					i_bigger = i_left;
			}
			else if (i_left < bottom)
			{
				i_bigger = i_left;
			}
			else
				break;
		}
	}
}