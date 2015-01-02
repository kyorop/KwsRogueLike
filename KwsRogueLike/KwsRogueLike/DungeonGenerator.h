#pragma once

class DungeonSize;
class DungeonData;
class MapManager;

class DungeonGenerator
{
public:
	MapManager Generate(const DungeonSize& sizeData, const DungeonData& dungeonData);
};
