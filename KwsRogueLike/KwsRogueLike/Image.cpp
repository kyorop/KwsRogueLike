#include <DxLib.h>
#include "Image.h"
#include "IDrawable.h"
#include "DxLibGraphic.h"


void ImageManager::Update(std::shared_ptr<GameManager> game) const
{
}

void ImageManager::SetDrawnObject(std::shared_ptr<IDrawable> drawn)
{
	const int thisLayer = drawn->GetLayer();
	bool pushed = false;
	for (auto itr = drawnList.begin(); itr != drawnList.end(); ++itr)
	{
		if ((*itr)->GetLayer() >= thisLayer)
		{
			drawnList.insert(itr, drawn);
			pushed = true;
			break;
		}
	}
	if (!pushed)
		drawnList.push_back(drawn);
}

void ImageManager::Initialize()
{
	for (auto drawn : drawnList)
	{
		drawn->Load(this);
	}
}

void ImageManager::Draw()
{
	for (auto drawn : drawnList)
	{
		drawn->Draw();
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
	int handle = DxLib::LoadGraph(imgFileAddress.data());
	handleList.push_back(handle);
	return handle;
}

std::vector<int> ImageManager::LoadDivGraph(const std::string& imgFileAddress, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	int* handle = new int[allNum];
	DxLib::LoadDivGraph(imgFileAddress.data(), allNum, xNum, yNum, xSize, ySize, handle);
	std::vector<int> vHandle(&handle[0], &handle[allNum]);
	delete[] handle;
	copy(handleList.begin(), handleList.end(), vHandle.begin());
	return vHandle;
}