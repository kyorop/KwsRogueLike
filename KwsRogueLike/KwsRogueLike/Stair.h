#pragma once
#include "ObjectBase.h"
#include "IDrawable.h"

class Stair:public ObjectBase, public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Stair(const Vector2& coord) :ObjectBase(coord){}

private:
	int handle;
};
