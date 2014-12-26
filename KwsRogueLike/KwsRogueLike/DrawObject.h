#pragma once
#include "ObjectBase.h"
#include "IDrawable.h"

class DrawObject:public ObjectBase, public IDrawable
{
public:
	bool GetDrawFlag() override;
	bool IsDead() override;
	void SetDrawFlag(bool isDrawble);
	void Kill();

	explicit DrawObject(const Vector2& coord)
		: ObjectBase(coord)
	{
	}

private:
	bool isDrawable = true;
	bool isDead = false;
};
