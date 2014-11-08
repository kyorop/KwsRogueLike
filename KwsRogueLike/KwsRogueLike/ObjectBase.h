#pragma once
#include <memory>
#include "IDrawable.h"

class Vector2;
class ObjectBase
	:public IDrawable
{
private:
	std::shared_ptr<Vector2> coordinate;
	int layer;

public:
	ObjectBase();
	~ObjectBase();

protected:
	void SetCoordinate(int x, int y);
	void SetCoordinate(const Vector2& coordinate);
	Vector2 GetCoordinate()const;
	void AddCoordinate(int x, int y);
};

