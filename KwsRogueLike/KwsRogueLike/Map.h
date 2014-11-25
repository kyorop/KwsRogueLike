#pragma once
#include <vector>
#include <array>
#include <memory>
#include "idrawable.h"
#include "generalconstant.h"

using namespace GeneralConstant;

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
	std::array <std::array<std::shared_ptr<MapObject>, entireWidth>, entireHeight> map;
	int handle_wall ;
	int handle_floor;
	int handle_path ;
public:
	void CreateMap();
	int GetFloor();
//	void DrawDungeon();
	void DebugMode();
	void Move();
	bool IsMovable();
	void Draw() override;
};