#pragma once
#include <memory>

class Screen;
class Vector2;
class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase();

private:
	std::shared_ptr<Vector2> coordinate;
	int layer;

public:
	void SetCoordinate(int x, int y);
	void SetCoordinate(const Vector2& coordinate);
	Vector2 GetCoordinate()const;
	void AddCoordinate(int x, int y);
	void AddCoordinate(const Vector2& v);
	Vector2 GetDrawCoord();
};

