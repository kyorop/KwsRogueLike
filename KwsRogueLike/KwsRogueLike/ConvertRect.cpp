#include "ConvertRect.h"
#include  "Rect.h"

Rect RectUtils::ConvertToComponent(Rect const& rect, int x_divisor, int y_divisor)
{
	return Rect(rect.x1 / x_divisor, rect.y1 / y_divisor, rect.x2 / x_divisor, rect.y2 / y_divisor);
}