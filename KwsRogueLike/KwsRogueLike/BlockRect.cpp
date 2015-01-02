#include "BlockRect.h"
#include "Component.h"

BlockRect::BlockRect(const Component& leftTop, const Component& rightBottom)
	:leftTop(std::make_unique<Component>(leftTop)),
	rightBottom(std::make_unique<Component>(rightBottom))
{
}

BlockRect::BlockRect(const BlockRect& rhs)
{
	leftTop = std::make_unique<Component>(*rhs.leftTop);
	rightBottom = std::make_unique<Component>(*rhs.rightBottom);
}

size_t BlockRect::Width()
{
	return rightBottom->j - leftTop->j + 1;
}

size_t BlockRect::Height()
{
	return rightBottom->i - leftTop->i + 1;
}

Component BlockRect::LeftTop()
{
	return *leftTop;
}

Component BlockRect::RightBottom()
{
	return *rightBottom;
}

