#pragma once
#include <vector>
#include <memory>
#include <array>
#include "idrawable.h"
#include "generalconstant.h"

class ObjectBase;
class ScrollingMovement;
class MysteryDungeonMaker;
enum MapComponent;
class Map
	:public IDrawable
{
public:
	Map();
	~Map();
private:
	int floor;
	std::vector<std::vector<std::shared_ptr<ObjectBase>>> map;
	std::shared_ptr<ScrollingMovement> scroller;
private:
public:
	void CreateMap();
	int GetFloor();
	void DebugMode();
	void Move();
	bool IsMovable();
	void Draw() override;
};