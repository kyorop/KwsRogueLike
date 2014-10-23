#pragma once

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

	void MakeRoom(const Component& startPoint, int roomWidth, int roomHeight);
	void MakePath();
	void ConnectAdjacentRoom(const Section& center, Direction to, const Section& around);
};