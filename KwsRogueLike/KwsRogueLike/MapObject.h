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
	void Scroll(const Vector2& v) override;

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
	static Direction direction;
	static int frameCount;
	static bool isMoving;

private:
	void Moving();

public:
	void SetMapComponent(MysteryDungeonMaker::MapComponent mapComponent);
	MysteryDungeonMaker::MapComponent GetMapComponent()const;
	char r_input;
};