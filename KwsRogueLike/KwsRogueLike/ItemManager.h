#pragma once
#include "GameManager.h"
#include <vector>

class DungeonSize;
class DungeonData;
class Meat;
class Vector2;

class ItemManager : public GameManager
{
public:
	ItemManager(){}

	void Initialize() override;
	void Finalize() override;
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	void Update(GameScene* game) override;

	void Add(const Meat& meat);
private:
	std::vector<std::shared_ptr<Meat>> meats;
	std::vector<std::shared_ptr<Meat>>::iterator FindSamePosItem(const Vector2& playerCoord);
};
