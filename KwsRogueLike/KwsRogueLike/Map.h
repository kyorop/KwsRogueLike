#pragma once
#include <vector>

class MapObject;
class Map
{
public:
	Map();
	void CreateMap();
	~Map();
private:
	int floor;
	//std::vector<std::vector<int>> map;
	std::vector<std::vector<const MapObject&>> map;
	int handle_wall ;
	int handle_floor;
	int handle_path ;
public:
	int GetFloor();
	void DrawDungeon();
	void DebugMode();
	void Move();
	bool IsMovable();
};