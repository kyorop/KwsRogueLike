#include <algorithm>
#include <functional>
#include <utility>
#include "DungeonMakerHelper.h"
#include "Section.h"
#include "Component.h"


bool DungeonMakerHelper::HasComponent(std::vector<Section*> const& sections, Component const& component)
{
	for (int i = 0; i < sections.size();i++)
	{
		if (sections[i]->GetComponent() == component)
			return true;
	}

	return false;
}

std::vector<Section*> DungeonMakerHelper::GetFewestMember(std::vector<std::vector<Section*>> members)
{
	std::vector<int> sizes;
	for (int i = 0; i < members.size(); i++)
		sizes.push_back(members[i].size());

	auto maxItr = std::max_element(sizes.begin(), sizes.end());

	return members[std::distance(sizes.begin(), maxItr)];
}

void DungeonMakerHelper::SortByGroupSize(std::vector<std::vector<Section*>>* groups)
{
	std::vector <std::pair<int, int>> maps;//<size, index>
	for (int i = 0; i < groups->size(); i++)
	{
		maps.push_back(std::make_pair((*groups)[i].size(), i));
	}
	std::sort(maps.begin(), maps.end());
	
	std::vector<std::vector<Section*>> sorted;
	for (int i = 0; i < maps.size(); i++)
	{
		int index = maps[i].second;
		sorted.push_back((*groups)[index]);
	}

	*groups = sorted;
}