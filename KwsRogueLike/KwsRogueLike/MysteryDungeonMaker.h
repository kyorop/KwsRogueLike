#pragma once
#include <vector>

class Rect;
class Section;
class Component;
class MysteryDungeonMaker
{
private:
	const int mapWidth;//���̐�
	const int mapHeight;
	const int sectionWidth;//��̋��̒��̃}�X�̐�
	const int sectionHeight;
	const int minRoomWidth;
	const int minRoomHeight;
	int** map;
	Section** section;

public:
	enum MapObject
	{
		WALL,
		FLOOR,
		PATH,
	};
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};

public:
	explicit MysteryDungeonMaker(int mapWidth, int mapHeight, int sectionWidth, int sectionHeight);
	~MysteryDungeonMaker();
	int** CreateDungeon();

private:
	void NewMap();
	void DeleteMap();
	void ResetMap();

	void MakeRoom(const Component& sectionStartPoint, int roomWidth, int roomHeight);
	void MakePath();
	void ConnectAdjacentRoom(Section *center, Section *around);
	void RemoveOneRoom(const Rect& room);
	std::vector<std::vector<Section*>> ClassifyGroups();
	std::vector<Component> SearchShortestRoute(const Section& start);
};