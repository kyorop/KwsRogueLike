#pragma once
#include "DrawObject.h"

class Floor
	:public DrawObject
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Floor(const Vector2& v)
		:DrawObject(v)
	{
	}

	~Floor();
};
