#pragma once

class Section;
class Component;
class MysteryDungeonMaker
{
private:
	const int mapWidth;//‹æ‰æ‚Ì”
	const int mapHeight;
	const int sectionWidth;//ˆê‚Â‚Ì‹æ‰æ‚Ì’†‚Ìƒ}ƒX‚Ì”
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
	int id;
	void MakePath();
	void ConnectAdjacentRoom(Section *center, Section *around);
};