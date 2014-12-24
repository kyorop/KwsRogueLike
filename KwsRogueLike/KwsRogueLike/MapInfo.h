#pragma once

enum class ObjectTypeOnMap
{
	ENEMY,
	PLAYER,
	TRAP,
	ITEM,
	WALL, //壊せる壁
	FLOOR, //床
	PATH, //通路
	UNBRAKABLEWALL, //壊せない壁
	STAIR //階段、１フロア１つまで
};

struct MapInformation
{
	bool isEnemy;
	bool isPlayer;
	bool isTrap;
	bool isItem;
	bool isStair;
	bool isWall;
	bool isFloor;
	bool isPath;

	MapInformation()
		:isEnemy(false),
		isPlayer(false),
		isTrap(false),
		isItem(false),
		isStair(false),
		isWall(false),
		isFloor(false),
		isPath(false)
	{}
};