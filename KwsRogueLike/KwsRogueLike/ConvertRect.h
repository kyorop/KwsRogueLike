#pragma once

class Rect;

namespace RectUtils
{
	Rect ConvertToComponent(const Rect& rect, int x_divisor, int y_divisor);
}