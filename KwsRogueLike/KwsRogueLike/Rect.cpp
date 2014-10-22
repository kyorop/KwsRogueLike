#include "Rect.h"

Rect::Rect(int x1, int y1, int x2, int y2)
	:x1(x1),
	y1(y1),
	x2(x2),
	y2(y2)
{
}

Rect::Rect()
{
}

Rect::~Rect()
{
}

Rect Rect::ConvertToComponent(int x_divisor, int y_divisor)
{
	return Rect(x1 / x_divisor, y1 / y_divisor, x2 / x_divisor, y2 / y_divisor);
}

int Rect::Width()
{
	return x2 - x1;
}

int Rect::Height()
{
	return y2 - y1;
}