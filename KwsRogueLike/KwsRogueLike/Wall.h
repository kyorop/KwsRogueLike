#pragma once
#include "DrawObject.h"

class Screen;
class Wall
	:public DrawObject
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Wall(const Vector2& v)
		:DrawObject(v)
	{
	}

	~Wall();
};
