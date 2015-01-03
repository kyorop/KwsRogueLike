#pragma once
#include "GameManagerFactory.h"

class ItemManager;
class RoomDataStores;
class DungeonSize;

class ItemManagerFactory : GameManagerFactory
{
public:
	ItemManagerFactory(const DungeonSize& sizeData, const RoomDataStores& roomData);

	std::shared_ptr<GameManager> Create() override;

private:
	std::unique_ptr<DungeonSize> size;
	std::unique_ptr<RoomDataStores >roomData;

	void GenerateItem(ItemManager& manager);
};
