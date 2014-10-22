#pragma once 

class Rect
{
public:
	int x1;
	int y1;
	int x2;
	int y2;

public:
	Rect(int x1, int y1, int x2, int y2);
	Rect();
	~Rect();

	Rect ConvertToComponent(int x_divisor, int y_divisor);
	int Width();
	int Height();
};