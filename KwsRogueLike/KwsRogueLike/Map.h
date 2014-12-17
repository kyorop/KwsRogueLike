#pragma once
#include <vector>
#include <memory>
#include <array>
#include "idrawable.h"
#include "generalconstant.h"
#include "MysteryDungeonMaker.h"
#include "IGameProcess.h"
#include "IImageAcceptor.h"

class MapInfo;
class ObjectBase;
class MapManager
	:public IGameProcess, public IImageAcceptor
{
public:
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	void Update(GameManager* game) const override;
	
	explicit MapManager(std::shared_ptr<MapInfo> mapInfo);
	~MapManager();

	void CreateMap(const std::vector<std::vector<MysteryDungeonMaker::MapComponent>>& mapPlan);
	void DebugMode();
	void Move();
private:
	std::vector<std::vector<std::shared_ptr<IDrawable>>>map;
	std::shared_ptr<MapInfo> mapInfo;
};