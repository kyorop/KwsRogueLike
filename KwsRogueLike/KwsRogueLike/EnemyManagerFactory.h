#pragma once
#include "GameManagerFactory.h"

class DungeonSize;
class RoomDataStores;

class EnemyManagerFactory:public GameManagerFactory
{
public:
	std::shared_ptr<GameManager> Create(const DungeonSize& sizeData, const RoomDataStores& roomData) override;
};
