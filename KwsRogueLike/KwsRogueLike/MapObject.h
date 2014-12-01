#pragma once
#include "mysterydungeonmaker.h"
#include "objectbase.h"
#include "iscrollable.h"
#include "idrawable.h"

class Vector2;
class MapObject
	:public ObjectBase/*, public IScrollable, public IDrawable*/
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
	virtual void Draw()
	{
		
	}
};