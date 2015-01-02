#pragma once
#include <memory>

class Vector2;
class BlockRect;

class RoomData
{
public:
	explicit RoomData(const BlockRect& rect);
	
	BlockRect Data();

	Vector2 LeftTopCoord(size_t width, size_t height);

	Vector2 RightBottomCoord(size_t width, size_t height);

private:
	std::unique_ptr<BlockRect> room;
};
