#pragma once
#include <memory>

class DungeonSize;
class RoomDataStores;
class GameManager;

class GameManagerFactory
{
public:
	virtual ~GameManagerFactory(){}
	virtual std::shared_ptr<GameManager> Create(const DungeonSize& sizeData, const RoomDataStores& roomData) = 0;
};
