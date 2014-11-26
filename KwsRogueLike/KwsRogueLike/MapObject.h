#pragma once
#include "mysterydungeonmaker.h"
#include "objectbase.h"
#include "iscrollable.h"
#include "idrawable.h"

class Vector2;
class MapObject
	:public ObjectBase, public IScrollable, public IDrawable
{
public:
	explicit MapObject();
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
	char r_input;
	void Scroll() override;
};