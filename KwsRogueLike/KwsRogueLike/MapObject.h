#pragma once
#include "mysterydungeonmaker.h"
#include "objectbase.h"
#include "iscrollable.h"
#include "idrawable.h"

class MapObject
	:public ObjectBase, IScrollable, IDrawable
{
public:
	MapObject();
	virtual ~MapObject();

	enum Direction
	{
		STOP = -1, 
		UP,
		UPRIGHT,
		RIGHT,
		DOWNRIGHT, 
		DOWN, 
		DOWNLEFT, 
		LEFT,
		UPLEFT,
	};

private:
	MysteryDungeonMaker::MapComponent mapState;
	Direction direction;
	int frameCount;
	bool isMoving;

private:
	void Moving();

public:
	void SetMapComponent(MysteryDungeonMaker::MapComponent mapComponent);
	MysteryDungeonMaker::MapComponent GetMapComponent()const;
	void Scroll() override;
};

