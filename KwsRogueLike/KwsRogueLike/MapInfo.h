#pragma once
#include <vector>
#include "mysterydungeonmaker.h"
class Vector2;

struct Information;
class MysteryDungeonMaker;
class MapInfo
{
public:
	explicit MapInfo(std::vector<std::vector<MysteryDungeonMaker::MapComponent>> mapData);
	~MapInfo();
	std::vector<std::vector<Information>> infos;
	Information GetInformation(const Vector2& coordinate);
};

struct Information
{
	bool isEnemy;
	bool isPlayer;
	bool isTrap;
	bool isItem;
	bool isStair;
	bool isWall;
	bool isFloor;

	Information()
		:isEnemy(false),
		isPlayer(false),
		isTrap(false),
		isItem(false),
		isStair(false),
		isWall(false),
		isFloor(false)
	{}
};