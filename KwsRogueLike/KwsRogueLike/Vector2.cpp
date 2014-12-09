#include "Vector2.h"

Vector2::Vector2()
{

}

Vector2::Vector2(int x, int y)
	:x(x),
	y(y)
{
}


Vector2::~Vector2()
{
}


//%演算子のオーバーロード。用途消えた
bool Vector2::operator%(int n) //Vector2型オブジェクトを渡し、ふたつの座標が共にnで割り切れたらtrueを返す。bool型でいいのか？
{
	if (this->x%n == 0 && this->y%n == 0)return true;
	else return false;
}

void Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

const Vector2 Vector2::operator+(const Vector2& rhs)const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

const Vector2 Vector2::operator-(const Vector2& rhs)const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

void Vector2::Set(int x, int y)
{
	this->x = x;
	this->y = y;
}