#pragma once
#include <vector>
#include "vector_2d.h"

class Section;
class Component;
struct ObjDataOnTile;
enum class ObjTypeOnMap;
namespace DungeonMakerHelper
{
	bool HasComponent(const std::vector<Section*>& sections, const Component& component);
	std::vector<Section*> GetFewestMember(std::vector<std::vector<Section*>> members);
	void SortByGroupSize(std::vector<std::vector<Section*>>* groups);
}