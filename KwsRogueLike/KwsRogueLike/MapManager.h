#pragma once
#include <vector>
#include <memory>
#include "IGameProcess.h"
#include "IImageAcceptor.h"
#include "vector_2d.h"

struct MapInformation;
class MapInfo;
class ObjectBase;
enum class ObjectTypeOnMap;
class IDrawable;

class MapManager
	:public IGameProcess, public IImageAcceptor
{
public:
	void Initialize() override;
	void Finalize() override;
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	void Update(GameManager* game) override;

	explicit MapManager(const KwsRogueLike::vector_2d<MapInformation>& mapPlan);
	~MapManager();

	void DebugMode();
	void Move();
private:
	std::vector<std::shared_ptr<IDrawable>> map;
};
