#pragma once
#include "ObjectBase.h"
#include "IDrawable.h"

class DrawObject:public ObjectBase, public IDrawable
{
public:
	bool IsVisible() final;

	bool IsDead() final;
	
	void Kill();

	explicit DrawObject(const Vector2& coord)
		: ObjectBase(coord)
	{
	}

protected:
	void SetDrawFlag(bool isDrawble);
	
	void MakeVisible();
	
	void MakeInvisible();

private:
	bool isVisible = true;
	
	bool isDead = false;
};
