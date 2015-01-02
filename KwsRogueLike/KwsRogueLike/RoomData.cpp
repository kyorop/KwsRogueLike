#include "RoomData.h"
#include "BlockRect.h"
#include "Vector2.h"
#include "Component.h"


RoomData::RoomData(const BlockRect& rect)
	:room(std::make_unique<BlockRect>(rect))
{
}

BlockRect RoomData::Data()
{
	return *room;
}

Vector2 RoomData::LeftTopCoord(size_t width, size_t height)
{
	auto leftTop = room->LeftTop();
	return Vector2(leftTop.j*width, leftTop.i*height);
}

Vector2 RoomData::RightBottomCoord(size_t width, size_t height)
{
	auto rightBottom = room->RightBottom();
	return Vector2(rightBottom.j*width, rightBottom.i*height);
}