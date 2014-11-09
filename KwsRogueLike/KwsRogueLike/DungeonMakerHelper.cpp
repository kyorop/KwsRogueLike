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