#pragma once
#include <memory>
#include "vector_2d.h"

class Component;
class DungeonData;

enum class DungeonBaseObj
{
	FLOOR,
	WALL,
	PATH,
};

class DungeonDrawing
{
public:
	DungeonDrawing(size_t i_size, size_t j_size);

	size_t GetRoomNum()
	{
		return roomNum;
	}

	void WriteDesigne(const Component& entry, DungeonBaseObj type);

	DungeonBaseObj GetType(const Component& entry);

private:
	size_t roomNum = 0;
	KwsRogueLike::vector_2d<DungeonBaseObj> drawing;
};
