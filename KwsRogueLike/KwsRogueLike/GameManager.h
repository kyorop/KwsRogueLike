#pragma once
#include <memory>
#include "MapInfo.h"
#include "vector_2d.h"
#include "IDrawable.h"


class ItemManager;
class Vector2;
class MapInfo;
class MapManager;
class Floor;
class ImageManager;
class Screen;
class PlayerBase;
class GameManager:public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	bool GetDrawFlag() override;
	bool IsDead() override;
	GameManager();
	void Initialize();
	void Main();
	void Finalize();
	Screen& GetScreen();
	std::shared_ptr<PlayerBase>& GetPlayer();
	const KwsRogueLike::vector_2d<MapInformation>& GetMapInfo();

private:
//	std::vector<std::shared_ptr<IGameProcess>> gameObjects;
	std::shared_ptr<ImageManager> image;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<PlayerBase> player;
	std::shared_ptr<MapManager> mapManager;
	std::shared_ptr<ItemManager> itemManager;
	KwsRogueLike::vector_2d<MapInformation> mapPlan;
};
