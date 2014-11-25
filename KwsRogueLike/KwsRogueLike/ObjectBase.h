#pragma once
#include <memory>

class Vector2;
class ObjectBase
{
private:
	std::shared_ptr<Vector2> coordinate;
	int layer;

public:
	ObjectBase();
	virtual ~ObjectBase();

protected:
	void SetCoordinate(int x, int y);
	void SetCoordinate(const Vector2& coordinate);
	Vector2 GetCoordinate()const;
	void AddCoordinate(int x, int y);
};

