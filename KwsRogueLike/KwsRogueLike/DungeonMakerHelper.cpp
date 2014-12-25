#include <algorithm>
#include <functional>
#include <utility>
#include "DungeonMakerHelper.h"
#include "Section.h"
#include "Component.h"
#include "MapInfo.h"
#include <random>
#include <ctime>
#include "Rect.h"


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

void DungeonMakerHelper::SetMapTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<ObjectTypeOnMap>& map, const KwsRogueLike::vector_2d<Section>& sections)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			switch (map[i][j])
			{
			case ObjectTypeOnMap::WALL:
				info[i][j].isWall = true;
				break;
			case ObjectTypeOnMap::FLOOR:
				info[i][j].isFloor = true;
				break;
			case ObjectTypeOnMap::PATH:
				info[i][j].isPath = true;
				break;
			default: break;
			}
		}
	}

	//ŠK’i‚ÌˆÊ’uŒˆ‚ß
	std::vector<Component> roomSection;
	for (auto line : sections)
	{
		for (auto section : line)
		{
			if (section.HasRoom())
				roomSection.push_back(section.GetComponent());
		}
	}

	std::mt19937 engine(static_cast<unsigned int>(time(nullptr)));
	std::uniform_int_distribution<int> section_picker(0, roomSection.size() - 1);
	int i_havingStair = section_picker(engine);
	const Section* section_havingStair = &sections[roomSection[i_havingStair].i][roomSection[i_havingStair].j];

	std::uniform_int_distribution<int> i_picker(section_havingStair->GetRoom().y1, section_havingStair->GetRoom().y2);
	std::uniform_int_distribution<int> j_picker(section_havingStair->GetRoom().x1, section_havingStair->GetRoom().x2);
	int i_stair = i_picker(engine);
	int j_stair = j_picker(engine);

	info[i_stair][j_stair].isStair = true;
}

void DungeonMakerHelper::SetItemTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<Section>& sections, size_t itemMin, size_t itemMax)
{
	std::vector<const Section*> roomSection;
	for (auto& line : sections)
	{
		for (auto& section : line)
		{
			if (section.HasRoom())
				roomSection.push_back(&section);
		}
	}

	std::mt19937 engine(static_cast<unsigned int>(time(nullptr)));
	std::uniform_int_distribution<size_t> itemNum_picker(1, roomSection.size()-1);
	const size_t itemNum = itemNum_picker(engine);

	std::vector<const Section*> itemRooms;
	std::uniform_int_distribution<size_t> itemSectionPicker(0, roomSection.size() - 1);
	for (size_t i = 0; i < itemNum; i++)
	{
		itemRooms.push_back(roomSection[itemSectionPicker(engine)]);
	}

	std::vector<Component> itemComps;
	for (auto itemRoom : itemRooms)
	{
		std::uniform_int_distribution<size_t> i_picker(itemRoom->GetRoom().y1, itemRoom->GetRoom().y2);
		std::uniform_int_distribution<size_t> j_picker(itemRoom->GetRoom().x1, itemRoom->GetRoom().x2);
		itemComps.push_back(Component(i_picker(engine), j_picker(engine)));
	}

	for (auto& itemComp : itemComps)
	{
		info[itemComp.i][itemComp.j].isItem = true;
	}
}

void DungeonMakerHelper::SetEnemyTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<Section>& sections, size_t enemyMin, size_t enemyMax)
{
}

void DungeonMakerHelper::SetTrapTo(KwsRogueLike::vector_2d<MapInformation>& info, const KwsRogueLike::vector_2d<Section>& sections, size_t trapMin, size_t trapMax)
{
}	