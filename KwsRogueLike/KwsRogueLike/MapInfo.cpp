#include "MapInfo.h"



MapInfo::MapInfo(std::vector<std::vector<MysteryDungeonMaker::MapComponent>> mapData)
{
	for (std::vector<MysteryDungeonMaker::MapComponent> line : mapData)
	{
		infos.push_back(std::vector<Information>());
		for (MysteryDungeonMaker::MapComponent block : line)
		{
		}
	}

	for (int i = 0; i < mapData.size(); i++)
	{
		infos.push_back(std::vector<Information>());
		for (int j = 0; j < mapData[i].size();j++)
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

}