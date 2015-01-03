#include "ItemManagerFactory.h"
#include "ItemManager.h"
#include "Meat.h"
#include "vector2.h"
#include "RoomData.h"
#include "DungeonSize.h"
#include "BlockRect.h"
#include "Component.h"

ItemManagerFactory::ItemManagerFactory(const DungeonSize& sizeData, const RoomDataStores& roomData)
{
	size = std::make_unique<DungeonSize>(sizeData);
	this->roomData = std::make_unique<RoomDataStores>(roomData);
}

std::shared_ptr<GameManager> ItemManagerFactory::Create()
{
	auto manager = std::make_shared<ItemManager>();
	GenerateItem(*manager);
	return manager;
}

void ItemManagerFactory::GenerateItem(ItemManager& manager)
{
	const size_t roomNum = roomData->RoomNum();
	for (size_t i = 0; i < roomNum; ++i)
	{
		auto room = roomData->Data(i);
		auto coord = room.LeftTopCoord(32, 32);
		manager.Add(Meat(coord));
	}
}