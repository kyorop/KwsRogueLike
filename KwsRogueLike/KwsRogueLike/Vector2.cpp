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

bool Vector2::operator%(int n) //Vector2�^�I�u�W�F�N�g��n���A�ӂ��̍��W������n�Ŋ���؂ꂽ��true��Ԃ��Bbool�^�ł����̂��H
{
	if (this->x%n == 0 && this->y%n == 0)return true;
	else false;
}