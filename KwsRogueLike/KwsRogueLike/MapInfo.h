#pragma once
class MapInfo
{
public:
	bool isEnemy = false;
	bool isPlayer = false;
	bool isTrap = false;
	bool isItem = false;
	bool isStair = false;
	bool isWall = false; //falseならばななめ不可、trueならばななめ可
	MapInfo();
	~MapInfo();
};

