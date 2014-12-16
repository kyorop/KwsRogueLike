#include "MapInfo.h"
#include "vector2.h"
#include "EnemyBase.h"
#include "PlayerBase.h"

MapInfo::MapInfo(const std::vector<std::vector<MysteryDungeonMaker::MapComponent>>& mapData)
{
	for (size_t i = 0; i < mapData.size(); i++)
	{
		infos.push_back(std::vector<Information>());
		for (size_t j = 0; j < mapData[i].size(); j++)
		{
			infos[i].push_back(Information());
			switch (mapData[i][j])
			{
			case MysteryDungeonMaker::WALL:
				infos[i][j].isWall = true;
				break;
			case MysteryDungeonMaker::FLOOR:
				infos[i][j].isFloor = true;
				break;
			case MysteryDungeonMaker::PATH:
				break;
			case MysteryDungeonMaker::UNBRAKABLEWALL:
				break;
			case MysteryDungeonMaker::STAIR:
				break;
			default: break;
			}
		}
	}
}

MapInfo::~MapInfo()
{
}

Information MapInfo::GetInformation(const Vector2& coordinate)
{
	return infos[coordinate.y / 32][coordinate.x / 32];
}

Vector2 MapInfo::GetPlayerCoord()
{
	return player->GetCoordinate();
}

void MapInfo::SetCharacter(std::shared_ptr<PlayerBase> player)
{
	this->player = player;
}