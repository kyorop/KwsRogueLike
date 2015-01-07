#include "ItemManagerFactory.h"
#include "ItemManager.h"
#include "Meat.h"
#include "vector2.h"
#include "RoomData.h"
#include "DungeonSize.h"
#include "BlockRect.h"
#include "Component.h"


std::shared_ptr<GameManager> ItemManagerFactory::Create(const DungeonSize& sizeData, const RoomDataStores& roomData)
{
	auto manager = std::make_shared<ItemManager>();
	GenerateItem(sizeData, roomData, manager);
	return manager;
}

void ItemManagerFactory::GenerateItem(const DungeonSize& sizeData, const RoomDataStores& roomData, std::shared_ptr<ItemManager>& manager)
{
	const size_t roomNum = roomData.RoomNum();
	for (size_t i = 0; i < roomNum; ++i)
	{
		auto room = roomData.Data(i);
		auto coord = room.LeftTopCoord(32, 32);
		manager->Add(Meat(coord));
	}
}