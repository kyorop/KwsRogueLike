#pragma once
#include <vector>

class Map
{
public:
	Map();
	void CreateMap();
	~Map();
private:
	int floor;
	std::vector<std::vector<int>> map;
	int handle_wall ;
	int handle_floor;
	int handle_path ;
public:
	int GetFloor();
	void DrawDungeon();
	void DebugMode();
};