#include "DungeonDrawing.h"
#include "Component.h"


DungeonDrawing::DungeonDrawing(size_t i_size, size_t j_size)
	:drawing(std::vector<std::vector<DungeonBaseObj>>(i_size, std::vector<DungeonBaseObj>(j_size)))
{
}

void DungeonDrawing::WriteDesigne(const Component& entry, DungeonBaseObj type)
{
	drawing[entry.i][entry.j] = type;
}

DungeonBaseObj DungeonDrawing::GetType(const Component& entry)
{
	return drawing[entry.i][entry.j];
}