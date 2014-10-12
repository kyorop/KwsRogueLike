#pragma once
class MapInfo
{
public:
	bool isEnemy = false;
	bool isPlayer = false;
	bool isTrap = false;
	bool isItem = false;
	bool isStair = false;
	bool isWall = false; //false‚È‚ç‚Î‚È‚È‚ß•s‰ÂAtrue‚È‚ç‚Î‚È‚È‚ß‰Â
	MapInfo();
	~MapInfo();
};

