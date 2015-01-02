#pragma once
#include <memory>

class Component;

class BlockRect
{
public:
	BlockRect(const Component& leftTop, const Component& rightBottom);

	BlockRect(const BlockRect& rhs);

	size_t Width();

	size_t Height();

	Component LeftTop();

	Component RightBottom();

private:
	std::unique_ptr<Component> leftTop;
	std::unique_ptr<Component> rightBottom;
};
