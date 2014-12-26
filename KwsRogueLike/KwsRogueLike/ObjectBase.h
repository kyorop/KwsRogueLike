#pragma once
#include <memory>

class Screen;
class Vector2;
class ObjectBase
{
public:
	explicit ObjectBase(const Vector2& coord);
	virtual ~ObjectBase();

private:
	std::shared_ptr<Vector2> coordinate;

public:
	void SetCoordinate(int x, int y);
	void SetCoordinate(const Vector2& coordinate);
	virtual Vector2 GetCoordinate()const;
	void AddCoordinate(int x, int y);
	void AddCoordinate(const Vector2& v);
	virtual Vector2 GetDrawCoord();
	size_t Get_i();
	size_t Get_j();
};

