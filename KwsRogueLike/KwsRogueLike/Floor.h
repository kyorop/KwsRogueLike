﻿#pragma once
#include "ObjectBase.h"

class Floor
	:public ObjectBase
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
public:
	explicit Floor(const Vector2& v);
	~Floor();
};
