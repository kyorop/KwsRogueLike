#pragma once

enum class ObjectTypeOnMap
{
	ENEMY,
	PLAYER,
	TRAP,
	ITEM,
	WALL, //‰ó‚¹‚é•Ç
	FLOOR, //°
	PATH, //’Ê˜H
	UNBRAKABLEWALL, //‰ó‚¹‚È‚¢•Ç
	STAIR //ŠK’iA‚PƒtƒƒA‚P‚Â‚Ü‚Å
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