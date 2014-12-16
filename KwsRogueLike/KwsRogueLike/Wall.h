#pragma once
#include "objectbase.h"
#include "IDrawable.h"

class Screen;
class Wall
	:public ObjectBase, public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Wall(const Vector2&  v);
	~Wall();
};
