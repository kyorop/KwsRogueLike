#pragma once

class ImageManager;
struct DivGraphData;

class IDrawable
{
public:
	virtual ~IDrawable(){};

	virtual int GetLayer() = 0;
	virtual void Load(ImageManager* manager) = 0;
	virtual void Draw(ImageManager* manager) = 0;
};

struct DivGraphData
{
	int allNum;
	int xNum;
	int yNum;
	int xSize;
	int ySize;
};