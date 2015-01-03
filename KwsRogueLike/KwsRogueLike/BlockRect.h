#pragma once
#include <memory>

class Component;

class BlockRect
{
public:
	BlockRect(size_t i1, size_t j1, size_t i2, size_t j2);

	BlockRect(const BlockRect& rhs);

	size_t Width();

	size_t Height();

	Component LeftTop();

	Component RightBottom();

private:
	std::unique_ptr<Component> leftTop;
	std::unique_ptr<Component> rightBottom;
};
