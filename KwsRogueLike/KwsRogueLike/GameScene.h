#pragma once
#include <memory>
#include "IDrawable.h"


class DungeonData;
class ItemManager;
class Vector2;
class MapInfo;
class MapManager;
class Floor;
class ImageManager;
class Screen;
class PlayerBase;
class GameManager;

class GameScene:public IDrawable
{
public:
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;
	bool GetDrawFlag() override;
	bool IsDead() override;
	GameScene();
	void Initialize();
	void Main();
	void Finalize();
	Screen& GetScreen();
	std::shared_ptr<PlayerBase>& GetPlayer();

private:
	std::shared_ptr<ImageManager> image;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<PlayerBase> player;
	std::shared_ptr<MapManager> mapManager;
	std::shared_ptr<GameManager> itemManager;
	std::shared_ptr<DungeonData> dungeonData;
};
