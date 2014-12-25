#pragma once
#include <vector>
#include "vector_2d.h"

class Rect;
class Section;
class Component;
class MapObject;
enum class ObjectTypeOnMap;
struct MapInformation;

class MysteryDungeonMaker
{
public:
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};
private:
	const int mapWidth;//‹æ‰æ‚Ì”
	const int mapHeight;
	const int sectionWidth;//ˆê‚Â‚Ì‹æ‰æ‚Ì’†‚Ìƒ}ƒX‚Ì”
	const int sectionHeight;
	const int minRoomWidth;
	const int minRoomHeight;
	int roomNum;
	KwsRogueLike::vector_2d < ObjectTypeOnMap > map;
	KwsRogueLike::vector_2d<Section> sections;

public:
	MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight);
	~MysteryDungeonMaker();
	KwsRogueLike::vector_2d<MapInformation> CreateDungeon();
	void SetRoomNum(int roomNum);

private:
	void ResetMap();
	void ResetGroupId();

	void MakeRoom(const Component& section, int roomWidth, int roomHeight);
	void MakePath();
	void ConnectAdjacentRoom(Section *center, Section *around);
	void RemoveRoom(const Rect& room);
	std::vector<std::vector<Section*>> ClassifyGroups();
	std::vector<Component> SearchShortestRoute(const Section& start);
};