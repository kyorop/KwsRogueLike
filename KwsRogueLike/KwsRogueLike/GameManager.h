#pragma once
#include <memory>
#include "MapInfo.h"
#include "vector_2d.h"


class Vector2;
class MapInfo;
class MapManager;
class Floor;
class ImageManager;
class Screen;
class PlayerBase;
class GameManager
{
public:
	GameManager();
	void Initialize();
	void Main();
	void Finalize();
	Screen GetScreen();
	std::shared_ptr<PlayerBase> GetPlayer();
	KwsRogueLike::vector_2d<MapInformation>& GetMapInfo();

private:
	std::shared_ptr<ImageManager> image;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<PlayerBase> player;
	std::shared_ptr<MapManager> mapManager;
	KwsRogueLike::vector_2d<MapInformation> mapInfos;
};
