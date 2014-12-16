#include <DxLib.h>
#include "Image.h"
#include "IDrawable.h"
#include "GameManager.h"
#include "Screen.h"
#include "Vector2.h"

void ImageManager::Update(std::shared_ptr<GameManager> game) const
{
	*screenCoord = game->GetScreen().GetCoord();
}

ImageManager::ImageManager()
	:screenCoord(std::make_shared<Vector2>(0,0))
{
}

void ImageManager::SetDrawnObject(IDrawable* drawn)
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
	handleList.insert(end(handleList), begin(vHandle), end(vHandle));
	return vHandle;
}