#pragma once
#include <vector>

class Section;
class Component;
namespace DungeonMakerHelper
{
	bool HasComponent(const std::vector<Section*>& sections, const Component& component);
}