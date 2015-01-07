#pragma once
#include <vector>
#include <memory>

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

	~RoomData();

private:
	std::unique_ptr<BlockRect> room;
};


class RoomDataStores
{
public:
	size_t RoomNum()const;

	void Add(const BlockRect& data);

	RoomData Data(size_t i)const;
private:
	std::vector<RoomData> rooms;
};