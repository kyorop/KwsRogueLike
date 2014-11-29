#pragma once
#include <vector>
#include <memory>
#include <array>
#include "idrawable.h"
#include "generalconstant.h"
#include "MapObject.h"

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

private:
	void UpdateDirection(MapObject::Direction* direction);
	int frameCount;
	void GetMoving(Vector2* movement ,const MapObject::Direction direction);
public:
	void CreateMap();
	int GetFloor();
	void DebugMode();
	bool isMoving;
	bool r_input;
	MapObject::Direction direction;
	void Move();
	bool IsMovable();
	void Draw() override;
};