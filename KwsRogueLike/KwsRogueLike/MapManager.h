#pragma once
#include <vector>
#include <memory>
#include "IGameProcess.h"
#include "IImageAcceptor.h"


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

	void Update(GameManager* game) override;

	void Accept(const std::shared_ptr<ImageManager>& image) const override;

	void GenerateDungeon(const DungeonSize& sizeData, const DungeonData& dungeonData);

private:
	std::vector<std::shared_ptr<IDrawable>> map;
};
