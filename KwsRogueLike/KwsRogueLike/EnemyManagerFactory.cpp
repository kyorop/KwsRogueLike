#include "EnemyManagerFactory.h"
#include "EnemyManager.h"
#include "RoomData.h"
#include "Faily.h"
#include "DungeonSize.h"
#include "Vector2.h"

std::shared_ptr<GameManager> EnemyManagerFactory::Create(const DungeonSize& sizeData, const RoomDataStores& roomData)
{
	auto enemyMng = std::make_shared<EnemyManager>();

	for (size_t i = 0; i < roomData.RoomNum(); ++i)
	{
		RoomData data = roomData.Data(i);
		enemyMng->Add(std::make_shared<Faily>(data.RightBottomCoord(32,32)));
	}

	return enemyMng;
}