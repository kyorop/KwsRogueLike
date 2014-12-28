#include <DxLib.h>
#include "Image.h"
#include "IDrawable.h"
#include "HeapSort.h"
#include "DxLibGraphic.h"

void ImageManager::Update(GameManager* game)
{
	for (auto itr = drawnList.begin(); itr != drawnList.end(); ++itr)
	{
		if ((*itr)->IsDead())
		{
			drawnList.erase(itr);
			break;
		}
	}
}

ImageManager::ImageManager()
{
}

void ImageManager::AddDrawObject(const std::shared_ptr<IDrawable>& drawn)
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
	KwsRogueLike::Util::Image::DoHeapSort(drawnList);

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
	for (auto& handleItr : handleMap)
	{
		DeleteGraph(handleItr.second);
	}

	for (auto& divHandle : divHandleMap)
	{
		KwsRogueLike::Util::DeleteGraph(divHandle.second);
	}
}

int ImageManager::LoadGraph(const std::string& imgFileAddress)
{
	if(handleMap.find(imgFileAddress) == handleMap.end())
	{
		int handle = DxLib::LoadGraph(imgFileAddress.data());
		handleMap.insert(make_pair(imgFileAddress, handle));
		return handle;
	}
	return handleMap[imgFileAddress];
}

std::vector<int> ImageManager::LoadDivGraph(const std::string& imgFileAddress, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	if (divHandleMap.find(imgFileAddress) == divHandleMap.end())
	{
		auto divHandles = std::make_unique<int[]>(allNum);
		DxLib::LoadDivGraph(imgFileAddress.data(), allNum, xNum, yNum, xSize, ySize, divHandles.get());
		this->divHandleMap.insert(make_pair(imgFileAddress, std::vector<int>(&divHandles[0], &divHandles[allNum])));

		return this->divHandleMap[imgFileAddress];
	}
	else
	{
		auto& divHandles = this->divHandleMap[imgFileAddress];
		if (divHandles.size() >= allNum)
		{
			return std::vector<int>(divHandles[0], divHandles[allNum]);
		}
		else
		{
			KwsRogueLike::Util::DeleteGraph(divHandles);
			this->divHandleMap.erase(imgFileAddress);

			auto tempDivHandles = std::make_unique<int[]>(allNum);
			DxLib::LoadDivGraph(imgFileAddress.data(), allNum, xNum, yNum, xSize, ySize, tempDivHandles.get());
			this->divHandleMap.insert(make_pair(imgFileAddress, std::vector<int>(&tempDivHandles[0], &tempDivHandles[allNum])));

			return this->divHandleMap[imgFileAddress];
		}
	}
}