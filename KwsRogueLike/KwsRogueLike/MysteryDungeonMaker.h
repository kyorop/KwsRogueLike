#pragma once
#include <vector>

class Rect;
class Section;
class Component;
class MapObject;
class MysteryDungeonMaker
{
public:
	enum MapComponent
	{
		WALL, //壊せる壁
		FLOOR, //床
		PATH, //通路
		UNBRAKABLEWALL, //壊せない壁
		STAIR //階段、１フロア１つまで
	};
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};
private:
	const int mapWidth;//区画の数
	const int mapHeight;
	const int sectionWidth;//一つの区画の中のマスの数
	const int sectionHeight;
	const int minRoomWidth;
	const int minRoomHeight;
	int roomNum;
	MapComponent** map;
	Section** section;

public:
	MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight);
	~MysteryDungeonMaker();
	std::vector<std::vector<MapComponent>> CreateDungeon();
	void SetRoomNum(int roomNum);

private:
	void NewMap();
	void DeleteMap();
	void ResetMap();
	void ResetGroupId();

	void MakeRoom(const Component& section, int roomWidth, int roomHeight);
	void MakePath();
	void ConnectAdjacentRoom(Section *center, Section *around);
	void RemoveRoom(const Rect& room);
	std::vector<std::vector<Section*>> ClassifyGroups();
	std::vector<Component> SearchShortestRoute(const Section& start);
};