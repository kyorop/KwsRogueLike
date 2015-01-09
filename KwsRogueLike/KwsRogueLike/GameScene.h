#pragma once
#include <memory>
#include <vector>
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
class IGameProcess;

class GameScene
{
public:
	GameScene();
	void Initialize();
	void Main();
	void Finalize();
	Screen& GetScreen();
	std::shared_ptr<PlayerBase>& GetPlayer();
	const DungeonData& GetDungeonData();

private:
	size_t currentFloor=1;

	std::shared_ptr<ImageManager> image;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<PlayerBase> player;
	std::shared_ptr<DungeonData> dungeonData;

	std::vector<std::shared_ptr<IGameProcess>> gameProcesses;
};
