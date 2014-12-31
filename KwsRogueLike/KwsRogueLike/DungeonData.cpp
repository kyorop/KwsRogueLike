#include "DungeonData.h"
#include "Component.h"

bool DungeonData::IsThis(ObjTypeOnMap type, size_t i, size_t j)const
{
	return mapPlan[i][j].Find(type);
}

void DungeonData::AddType(const Component& comp, ObjTypeOnMap type)
{
	mapPlan[comp.i][comp.j].Add(type);
}

void DungeonData::Merge(const DungeonData& anotherData)
{
	const size_t i_size = anotherData.mapPlan.size();
	const size_t j_size = anotherData.mapPlan[0].size();
	for (size_t i = 0; i < i_size; ++i)
	{
		for (size_t j = 0; j < j_size; ++j)
		{
			this->mapPlan[i][j].Merge(anotherData.mapPlan[i][j]);
		}
	}
}



bool ObjDataOnTile::Find(ObjTypeOnMap type)const
{
	return find(objTypes.begin(), objTypes.end(), type) != objTypes.end();
}

void ObjDataOnTile::Add(ObjTypeOnMap object)
{
	if (!Find(object))
	{
		objTypes.push_back(object);
	}
}

void ObjDataOnTile::Merge(const ObjDataOnTile& anotherData)
{
	for (auto& type : anotherData.objTypes)
	{
		this->Add(type);
	}
}