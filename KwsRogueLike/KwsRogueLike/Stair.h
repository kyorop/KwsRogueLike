#pragma once
#include "DrawObject.h"

class Stair:public DrawObject
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Stair(const Vector2& coord) :DrawObject(coord){}

private:
	int handle;
};
