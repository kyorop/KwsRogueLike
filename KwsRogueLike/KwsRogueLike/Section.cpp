#include "Section.h"
#include "Component.h"
#include "Rect.h"

Section::Section()
	:myComponent(new Component),
	room(new Rect),
	hasRoom(false)
{

}

Section::~Section()
{
	delete myComponent;
	delete room;
}

void Section::PutRoomMark()
{
	hasRoom = true;
}

void Section::SetComponent(int i, int j)
{

}

void Section::SetComponent(Component component)
{

}

void Section::SetRoom(int i, int j, int w, int h)
{
	room->x1 = j;
	room->y1 = i;
	room->x2 = j + w;
	room->y2 = i + h;
}

void Section::SetRoom(Rect const& rect)
{
	*room = rect;
}