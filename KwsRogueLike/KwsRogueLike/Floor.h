#pragma once
#include "objectbase.h"
#include "IDrawable.h"

class Floor
	:public ObjectBase, public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
public:
	explicit Floor(const Vector2& v);
	~Floor();
};
