#include <algorithm>
#include <queue>
#include "Section.h"
#include "Component.h"
#include "Rect.h"

Section::Section()
	:myComponent(new Component(0,0)),
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

bool Section::HasRoom()
{
	return hasRoom;
}

void Section::SetComponent(int i, int j)
{
	myComponent->i = i;
	myComponent->j = j;
}

void Section::SetComponent(const Component& component)
{
	*myComponent = component;
}

Component Section::GetComponent() const
{
	return *myComponent;
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

Rect Section::GetRoom() const
{
	return *room;
}

void Section::SetRoomConnected(const Section* room)
{
	roomConnected.push_back(room);
}

bool Section::isConnected(Section const& section)
{
	std::queue<const Section*> next;
	next.push(this);
	while (!next.empty())
	{
		Section current_section = *next.front();
		next.pop();
		for (std::vector<const Section*>::iterator itr = roomConnected.begin(); itr != roomConnected.end(); ++itr)
		{
			if ((*itr)->EqualTo(current_section))
			{
				
			}
		}
	}
}

bool Section::EqualTo(Section const& section)const
{
	return *myComponent == section.GetComponent();
}

bool Section::operator==(Section const& section)
{
	return *myComponent == section.GetComponent();
}