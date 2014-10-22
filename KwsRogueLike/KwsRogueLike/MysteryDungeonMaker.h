#pragma once

class Vector2;
class ReducedMap;
class Section;
class Rect;
class Component;
class MysteryDungeonMaker
{
private:
	const int mapWidth;
	const int mapHeight;
	const int sectionWidth;
	const int sectionHeight;
	int** map;
	ReducedMap** rmap;
	Section** section;

public:
	enum MapObject
	{
		WALL,
		FLOOR,
		PATH,
		FOOD,
		ITEM,
	};

public:
	MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight);
	~MysteryDungeonMaker();
	int** CreateDungeon();
private:
	void NewMap();
	void DeleteMap();
	void MakeRoom(const Component& startPoint, int roomWidth, int roomHeight);
	void ResetMap();
	void MakePath();
	Vector2 ConvertToSectionCoord(const Vector2& mapCoord);
};