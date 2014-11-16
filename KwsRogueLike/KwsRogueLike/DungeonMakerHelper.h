#pragma once
#include <vector>

class Section;
class Component;
namespace DungeonMakerHelper
{
	bool HasComponent(const std::vector<Section*>& sections, const Component& component);
	std::vector<Section*> GetFewestMember(std::vector<std::vector<Section*>> members);
	void SortByGroupSize(std::vector<std::vector<Section*>>* groups);
}