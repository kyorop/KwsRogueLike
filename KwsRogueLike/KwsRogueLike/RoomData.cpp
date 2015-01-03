#include "RoomData.h"
#include "Vector2.h"
#include "Component.h"
#include "BlockRect.h"

RoomData::RoomData(const BlockRect& rect)
	:room(std::make_unique<BlockRect>(rect))
{
}

RoomData::RoomData(const RoomData& rhs)
{
	BlockRect rect = rhs.Data();
	room = std::make_unique<BlockRect>(rect);
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


size_t RoomDataStores::RoomNum()
{
	return rooms.size();
}

void RoomDataStores::Add(const BlockRect& data)
{
	rooms.push_back(RoomData(data));
}

RoomData RoomDataStores::Data(size_t i)
{
	return rooms[i];
}