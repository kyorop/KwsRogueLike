#pragma once
#include <vector>
#include <memory>
#include "idrawable.h"
#include "IGameProcess.h"
#include "IImageAcceptor.h"

struct MapInformation;
class MapInfo;
class ObjectBase;
enum class ObjectTypeOnMap;
class IDrawable;

class MapManager
	:public IGameProcess, public IImageAcceptor
{
public:
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	void Update(GameManager* game) override;

	~MapManager();

	void CreateMap(const std::vector<std::vector<MapInformation>>& mapPlan);
	void DebugMode();
	void Move();
	void Initialize(std::vector<std::vector<MapInformation>>& mapInfo);
private:
	std::vector<std::shared_ptr<IDrawable>> map;
};
