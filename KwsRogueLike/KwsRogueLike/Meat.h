#pragma once
#include "ObjectBase.h"

class Vector2;

class Meat:public ObjectBase
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Meat(const Vector2& coord)
		:ObjectBase(coord)
	{}
private:
	int handle;
};
