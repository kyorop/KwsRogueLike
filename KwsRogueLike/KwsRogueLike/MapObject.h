#pragma once
#include "ScrollObject.h"
#include "mysterydungeonmaker.h"

class MapObject :
	public ScrollObject
{
private:
	MysteryDungeonMaker::MapComponent mapState;
public:
	MapObject();
	~MapObject();
};

