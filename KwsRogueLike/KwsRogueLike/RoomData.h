#pragma once
#include <memory>
#include <vector>

class Vector2;
class BlockRect;

class RoomData
{
public:
	explicit RoomData(const BlockRect& rect);

	RoomData(const RoomData& rhs);
	
	BlockRect Data()const;

	Vector2 LeftTopCoord(size_t width, size_t height)const;

	Vector2 RightBottomCoord(size_t width, size_t height)const;

private:
	std::unique_ptr<BlockRect> room;
};


class RoomDataStores
{
public:
	size_t RoomNum();

	void Add(const BlockRect& data);

	RoomData Data(size_t i);
private:
	std::vector<RoomData> rooms;
};