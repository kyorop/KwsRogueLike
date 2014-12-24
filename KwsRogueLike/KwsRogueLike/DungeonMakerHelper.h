#pragma once
#include <vector>
#include "vector_2d.h"

class Section;
class Component;
struct MapInformation;
namespace DungeonMakerHelper
{
	bool HasComponent(const std::vector<Section*>& sections, const Component& component);
	std::vector<Section*> GetFewestMember(std::vector<std::vector<Section*>> members);
	void SortByGroupSize(std::vector<std::vector<Section*>>* groups);
	
	void SetItemTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<Section>& sections, size_t itemMin, size_t itemMax);
	void SetEnemyTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<Section>& sections, size_t enemyMin, size_t enemyMax);
	void SetTrapTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<Section>& sections, size_t trapMin, size_t trapMax);
}