#include <DxLib.h>
#include "Image.h"
#include "IDrawable.h"
#include "GameManager.h"
#include "Screen.h"
#include "Vector2.h"
#include "HeapSort.h"

void ImageManager::Update(GameManager* game)
{
	*screenCoord = game->GetScreen().GetCoord();

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
	KwasRogueLike::Util::Image::DoHeapSort(drawnList);

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