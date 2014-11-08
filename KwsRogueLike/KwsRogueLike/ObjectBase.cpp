#include "ObjectBase.h"
#include "Vector2.h"


ObjectBase::ObjectBase()
{
	coordinate = std::make_shared<Vector2>(0,0);
}


ObjectBase::~ObjectBase()
{
}

void ObjectBase::SetCoordinate(int x, int y)
{
	coordinate->x = x;
	coordinate->y = y;
}

void ObjectBase::SetCoordinate(Vector2 const& coordinate)
{
	this->coordinate->x = coordinate.x;
	this->coordinate->y = coordinate.y;
}

Vector2 ObjectBase::GetCoordinate()const
{
	return Vector2(coordinate->x, coordinate->y);
}

void ObjectBase::AddCoordinate(int x, int y)
{
	coordinate->x += x;
	coordinate->y += y;
}