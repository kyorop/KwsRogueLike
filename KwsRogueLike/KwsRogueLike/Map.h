#pragma once
#include <vector>
#include <memory>
#include <array>
#include "idrawable.h"
#include "generalconstant.h"
#include "MysteryDungeonMaker.h"
#include "IGameProcess.h"

class Screen;
class MapInfo;
class ObjectBase;
class ScrollingMovement;
class Vector2;
class MapManager
	:public IDrawable, public IGameProcess
{
public:
	void Update(std::shared_ptr<GameManager> game) const override;
	explicit MapManager(std::shared_ptr<MapInfo> mapInfo);
	~MapManager();
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
	bool stop;
	void Move();
	bool IsMovable();
	void Draw(const Screen& screen);
	void Draw();
};