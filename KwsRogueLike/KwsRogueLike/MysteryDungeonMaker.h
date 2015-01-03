#pragma once
#include <vector>
#include <memory>
#include "vector_2d.h"

class RoomDataStores;
class DungeonSize;
class Rect;
class Section;
class Component;
class MapObject;
enum class ObjTypeOnMap;
struct ObjDataOnTile;
class DungeonData;

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

	explicit MysteryDungeonMaker(const DungeonSize& dungeonSize);
	~MysteryDungeonMaker();

	void Initialize();
	void SetRoomNum(unsigned roomNum);

	DungeonData DungeonData();
	RoomDataStores RoomData();

private:
	std::unique_ptr<DungeonSize> dungeonSize;
	const int minRoomWidth = 4;
	const int minRoomHeight = 4;
	int roomNum = 0;
	KwsRogueLike::vector_2d<ObjTypeOnMap> tiles;
	KwsRogueLike::vector_2d<Section> sections;

	void ResetMap();
	void ResetGroupId();
	void CreateDungeon();
	void MakeRoom(const Component& sectionPos, int roomWidth, int roomHeight);
	void MakePath();
	void ConnectAdjacentRoom(Section* center, Section* around);
	void RemoveRoom(const Rect& room);
	std::vector<std::vector<Section*>> ClassifyGroups();
	std::vector<Component> SearchShortestRoute(const Section& start);
};