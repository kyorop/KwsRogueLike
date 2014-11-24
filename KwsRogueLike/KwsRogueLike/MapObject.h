#pragma once
#include "ScrollObject.h"
#include "mysterydungeonmaker.h"

class MapObject :
	public ScrollObject
{
private:
	MysteryDungeonMaker::MapObject mapState;
public:
	MapObject();
	~MapObject();
};

