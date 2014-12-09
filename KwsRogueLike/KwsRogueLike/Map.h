#pragma once
#include <vector>
#include <memory>
#include <array>
#include "idrawable.h"
#include "generalconstant.h"
#include "MysteryDungeonMaker.h"

class MapInfo;
class ObjectBase;
class ScrollingMovement;
class Vector2;
class Map
	:public IDrawable
{
public:
	explicit Map(std::shared_ptr<MapInfo> mapInfo);
	~Map();
private:
	int floor;
	std::vector<std::vector<std::shared_ptr<ObjectBase>>>map;
	std::shared_ptr<ScrollingMovement> scroller;
	std::shared_ptr<MapInfo> mapInfo;

	void Scroll(const Vector2& scrollAmount);
public:
	void CreateMap(const std::vector<std::vector<MysteryDungeonMaker::MapComponent>>& mapPlan);
	int GetFloor();
	void DebugMode();
	void Move();
	bool IsMovable();
	void Draw() override;
};