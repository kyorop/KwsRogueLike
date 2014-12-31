#include "ObjectBase.h"
#include "Vector2.h"
#include "Screen.h"
#include "GeneralConstant.h"

ObjectBase::ObjectBase(const Vector2& coord)
	:coord(std::make_shared<Vector2>(coord))
{
	this->coord->x = coord.x;
	this->coord->y = coord.y;
}

Vector2 ObjectBase::GetCoordinate()const
{
	return Vector2(coord->x, coord->y);
}

void ObjectBase::AddCoordinate(const Vector2& v)
{
	coord->x += v.x;
	coord->y += v.y;
}

size_t ObjectBase::Get_i()
{
	return coord->y / GeneralConstant::img_size_height;
}

size_t ObjectBase::Get_j()
{
	return coord->x / GeneralConstant::img_size_width;
}

Vector2 ObjectBase::GetDrawCoord()
{
	return *coord - Screen::GetCoord();
}