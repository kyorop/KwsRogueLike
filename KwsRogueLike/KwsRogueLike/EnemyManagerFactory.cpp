#include "EnemyManagerFactory.h"
#include "EnemyManager.h"
#include "RoomData.h"

std::shared_ptr<GameManager> EnemyManagerFactory::Create(const DungeonSize& sizeData, const RoomDataStores& roomData)
{
	auto enemyMng = std::make_shared<EnemyManager>();

	for (size_t i = 0; i < roomData.RoomNum(); ++i)
	{
		RoomData data = roomData.Data(i);

	}

	return enemyMng;
}