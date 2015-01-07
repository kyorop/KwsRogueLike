#include "RoomData.h"
#include "Vector2.h"
#include "BlockRect.h"
#include "Component.h"

RoomData::RoomData(const BlockRect& rect)
	:room(std::make_unique<BlockRect>(rect))
{
}

RoomData::RoomData(const RoomData& rhs)
{
	Component lefttop = rhs.room->LeftTop();
	Component rightbottom = rhs.room->RightBottom();
	room = std::make_unique<BlockRect>(lefttop.i, lefttop.j, rightbottom.i, rightbottom.j);
//	BlockRect rect = rhs.Data();
//	room = std::make_unique<BlockRect>(rect);
}

BlockRect RoomData::Data()const
{
	return *room;
}

Vector2 RoomData::LeftTopCoord(size_t width, size_t height)const
{
	auto leftTop = room->LeftTop();
	return Vector2(leftTop.j*width, leftTop.i*height);
}

Vector2 RoomData::RightBottomCoord(size_t width, size_t height)const
{
	auto rightBottom = room->RightBottom();
	return Vector2(rightBottom.j*width, rightBottom.i*height);
}

RoomData::~RoomData()
{
}

size_t RoomDataStores::RoomNum()const
{
	return rooms.size();
}

void RoomDataStores::Add(const BlockRect& data)
{
	rooms.push_back(RoomData(data));
}

RoomData RoomDataStores::Data(size_t i)const
{
	return rooms[i];
}