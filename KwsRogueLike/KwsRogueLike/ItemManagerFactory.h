#pragma once
#include "GameManagerFactory.h"

class ItemManager;
class RoomDataStores;
class DungeonSize;

class ItemManagerFactory : GameManagerFactory
{
public:
	std::shared_ptr<GameManager> Create(const DungeonSize& sizeData, const RoomDataStores& roomData) override;

private:
	void GenerateItem(const DungeonSize& sizeData, const RoomDataStores& roomData, std::shared_ptr<ItemManager>& manager);
};
