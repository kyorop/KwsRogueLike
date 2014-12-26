#pragma once
#include "DrawObject.h"

class Screen;

class Path
	:public DrawObject
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	explicit Path(const Vector2& v)
		:DrawObject(v)
	{}
	~Path();
private:
	static int imgHandle;
};
