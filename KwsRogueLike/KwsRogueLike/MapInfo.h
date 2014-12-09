#pragma once
#include <vector>
#include "mysterydungeonmaker.h"
#include <memory>
class Vector2;

struct Information;
class MysteryDungeonMaker;
class MapInfo
{
public:
	explicit MapInfo(const std::vector<std::vector<MysteryDungeonMaker::MapComponent>>& mapData);
	~MapInfo();

private:
	std::shared_ptr<const Vector2> firstTileCoord;

public:
	std::vector<std::vector<Information>> infos;
	Information GetInformation(const Vector2& firstTileCood,  const Vector2& coordinate);
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