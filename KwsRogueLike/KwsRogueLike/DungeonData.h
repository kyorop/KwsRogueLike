#pragma once
#include "vector_2d.h"

class Component;
enum class ObjTypeOnMap;
struct ObjDataOnTile;
class DungeonData
{
public:
	DungeonData(size_t i_size, size_t j_size)
		:mapPlan(std::vector<std::vector<ObjDataOnTile>>(i_size, std::vector<ObjDataOnTile>(j_size)))
	{
	}

	bool IsThis(ObjTypeOnMap type, size_t i, size_t j)const;

	void AddType(const Component& comp, ObjTypeOnMap type);

	void Merge(const DungeonData& anotherData);

private:
	KwsRogueLike::vector_2d<ObjDataOnTile> mapPlan;
};

enum class ObjTypeOnMap
{
	ENEMY,
	PLAYER,
	TRAP,
	ITEM,
	WALL, //壊せる壁
	FLOOR, //床
	PATH, //通路
	UNBRAKABLEWALL, //壊せない壁
	STAIR //階段、１フロア１つまで
};

class ObjDataOnTile
{
private:
	std::vector<ObjTypeOnMap> objTypes;

public:
	size_t GetObjNum()
	{
		return objTypes.size();
	}

	bool Find(ObjTypeOnMap type)const;

	void Add(ObjTypeOnMap object);

	void Merge(const ObjDataOnTile& anotherData);
};