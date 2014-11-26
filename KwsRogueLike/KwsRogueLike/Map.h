#pragma once
#include <vector>
#include <memory>
#include "idrawable.h"
#include "generalconstant.h"

class MysteryDungeonMaker;
enum MapComponent;
class MapObject;
class Map
	:public IDrawable
{
public:
	Map();
	~Map();
private:
	int floor;
	std::vector<std::vector<std::shared_ptr<MapObject>>> map;
public:
	void CreateMap();
	int GetFloor();
	void DebugMode();
	void Move();
	bool IsMovable();
	void Draw() override;
};