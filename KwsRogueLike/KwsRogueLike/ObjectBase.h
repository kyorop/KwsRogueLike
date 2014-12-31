#pragma once
#include <memory>

class Screen;
class Vector2;
class ObjectBase
{
public:
	explicit ObjectBase(const Vector2& coord);
	
	virtual ~ObjectBase(){}

	virtual Vector2 GetCoordinate()const;

	void AddCoordinate(const Vector2& v);
	
	virtual Vector2 GetDrawCoord();
	
	size_t Get_i();
	
	size_t Get_j();

private:
	std::shared_ptr<Vector2> coord;
};

