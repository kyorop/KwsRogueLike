#include "BlockRect.h"
#include "Component.h"


BlockRect::BlockRect(size_t i1, size_t j1, size_t i2, size_t j2) 
	:leftTop(std::make_unique<Component>(i1,j1)),
	rightBottom(std::make_unique<Component>(i2,j2))
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

