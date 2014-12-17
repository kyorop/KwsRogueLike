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
		WALL, //�󂹂��
		FLOOR, //��
		PATH, //�ʘH
		UNBRAKABLEWALL, //�󂹂Ȃ���
		STAIR //�K�i�A�P�t���A�P�܂�
	};
	enum Direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};
private:
	const int mapWidth;//���̐�
	const int mapHeight;
	const int sectionWidth;//��̋��̒��̃}�X�̐�
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