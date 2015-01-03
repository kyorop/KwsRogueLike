#pragma once
#include <vector>
#include <memory>
#include "IGameProcess.h"
#include "IImageAcceptor.h"


class Component;
class DungeonSize;
class Vector2;
class DungeonData;
struct ObjDataOnTile;
class MapInfo;
class ObjectBase;
enum class ObjTypeOnMap;
class IDrawable;

enum class MapType
{
	FLOOR,
	WALL,
	PATH,
	STAIR,
};

class MapManager : public IGameProcess, public IImageAcceptor
{
public:
	void Initialize() override;

	void Finalize() override;

	void Update(GameScene* game) override;

	void Accept(const std::shared_ptr<ImageManager>& image) const override;

	void Add(const std::shared_ptr<IDrawable>& tile);

private:
	std::vector<std::shared_ptr<IDrawable>> map;
};
