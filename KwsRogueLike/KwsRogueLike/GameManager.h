#pragma once
#include <memory>


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

private:
	std::shared_ptr<ImageManager> image;
	std::shared_ptr<Screen> screen;
	std::shared_ptr<PlayerBase> player;
};
