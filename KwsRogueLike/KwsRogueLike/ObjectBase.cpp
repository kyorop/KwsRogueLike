#include "ObjectBase.h"
#include "Vector2.h"
#include "Screen.h"
#include "GeneralConstant.h"

ObjectBase::ObjectBase()
	:coordinate(std::make_shared<Vector2>(0, 0))
{
}

ObjectBase::ObjectBase(const Vector2& coord)
	:coordinate(std::make_shared<Vector2>(0, 0))
{
	coordinate->x = coord.x;
	coordinate->y = coord.y;
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

void ObjectBase::AddCoordinate(const Vector2& v)
{
	coordinate->x += v.x;
	coordinate->y += v.y;
}

size_t ObjectBase::Get_i()
{
	return coordinate->y / GeneralConstant::img_size_height;
}

size_t ObjectBase::Get_j()
{
	return coordinate->x / GeneralConstant::img_size_width;
}

Vector2 ObjectBase::GetDrawCoord()
{
	return *coordinate - Screen::GetCoord();
}