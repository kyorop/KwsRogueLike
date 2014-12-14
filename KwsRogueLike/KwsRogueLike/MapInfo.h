#pragma once
#include <vector>
#include "mysterydungeonmaker.h"
#include <memory>
class PlayerBase;
class ObjectBase;
class Vector2;

struct Information;
class MysteryDungeonMaker;
class MapInfo
{
public:
	explicit MapInfo(const std::vector<std::vector<MysteryDungeonMaker::MapComponent>>& mapData);
	~MapInfo();

	Information GetInformation(const Vector2& coordinate);

	Vector2 GetPlayerCoord();
	void SetCharacter(std::shared_ptr<PlayerBase> player);
private:
	std::vector<std::vector<Information>> infos;
	std::shared_ptr<PlayerBase> player;
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