﻿#pragma once
#include "objectbase.h"
#include "IDrawable.h"

class Screen;

class Path
	:public ObjectBase, public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	explicit Path(const Vector2& v);
	~Path();
private:
	static int imgHandle;
};
