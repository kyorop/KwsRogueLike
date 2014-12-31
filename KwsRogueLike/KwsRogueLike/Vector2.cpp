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


//%���Z�q�̃I�[�o�[���[�h�B�p�r������
bool Vector2::operator%(int n) //Vector2�^�I�u�W�F�N�g��n���A�ӂ��̍��W������n�Ŋ���؂ꂽ��true��Ԃ��Bbool�^�ł����̂��H
{
	if (this->x%n == 0 && this->y%n == 0)return true;
	else return false;
}

bool Vector2::operator==(const Vector2& rhs)const
{
	if (x == rhs.x && y == rhs.y)
		return true;
	else
		return false;
}

Vector2 Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
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