#pragma once
class MapInfo
{
public:
	bool isEnemy = false;
	bool isPlayer = false;
	bool isTrap = false;
	bool isItem = false;
	bool isStair = false;
	bool isWall = false; //false�Ȃ�΂ȂȂߕs�Atrue�Ȃ�΂ȂȂ߉�
	MapInfo();
	~MapInfo();
};

