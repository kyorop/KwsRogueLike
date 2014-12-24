#pragma once

enum class ObjectTypeOnMap
{
	ENEMY,
	PLAYER,
	TRAP,
	ITEM,
	WALL, //�󂹂��
	FLOOR, //��
	PATH, //�ʘH
	UNBRAKABLEWALL, //�󂹂Ȃ���
	STAIR //�K�i�A�P�t���A�P�܂�
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