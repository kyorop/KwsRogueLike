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

Section::Section(Section const& section)
	:myComponent(new Component),
	room(new Rect),
	hasRoom(section.HasRoom())
{
	*myComponent = *section.myComponent;
	*room = *section.room;
	roomConnected = section.roomConnected;
}

Section::~Section()
{
	delete myComponent;
	delete room;
}

void Section::RemoveRoom(Section* section)
{
	Component comp = section->GetComponent();
	for (auto itr = roomConnected.begin(); itr != roomConnected.end(); ++itr)
	{
		if ((*itr)->GetComponent() == comp)
		{
			itr = roomConnected.erase(itr);
			if (itr == roomConnected.end())
				break;
			--itr;
		}
	}
}

bool Section::HasRoom()const
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

	hasRoom = true;
}

void Section::SetRoom(Rect const& rect)
{
	*room = rect;
	hasRoom = true;
}

void Section::RemoveRoom()//todoçƒãAìIÇ…çÌèúÇµÇ»ÇØÇÍÇŒÇ»ÇÁÇ»Ç¢
{
	hasRoom = false;
	std::vector<Section*>::iterator itr_adjacentRoom;
	const Section me = *this;
	for (auto itr = roomConnected.begin(); itr != roomConnected.end(); ++itr)
	{
		(*itr)->RemoveRoom(this);
	}

	roomConnected.clear();
	delete room;
	room = new Rect;
}

Rect Section::GetRoom() const
{
	return *room;
}

void Section::SetRoomConnected(Section* room)
{
	roomConnected.push_back(room);
}

std::vector<Section*> Section::GetConnectedRooms()const
{
	return roomConnected;
}

bool Section::isConnectedTo(Section const& section)const
{
	std::queue<const Section*> next;
	next.push(this);
	std::vector<Component> comp_checked;

	while(!next.empty())
	{
		Section current_section = *next.front();
		comp_checked.push_back(current_section.GetComponent());
		next.pop();

		std::vector< Section*>::const_iterator itr;
		std::vector< Section*> adjacentRooms = current_section.GetConnectedRooms();
		for (itr = adjacentRooms.begin(); itr != adjacentRooms.end(); ++itr)
		{
			std::vector<Component>::iterator itr_checked_comp;
			itr_checked_comp = find(comp_checked.begin(), comp_checked.end(), (*itr)->GetComponent());
			if (itr_checked_comp != comp_checked.end())
				continue;
			if((*itr)->EqualTo(section))
				return true;

			next.push(*itr);
		}
	}

	return false;
}

bool Section::EqualTo(Section const& section)const
{
	return *myComponent == section.GetComponent();
}

bool Section::operator==(Section const& section)
{
	return *myComponent == section.GetComponent();
}

void Section::operator=(Section const& section)
{
	delete myComponent;
	delete room;

	myComponent = new Component;
	room = new Rect;
	*myComponent = section.GetComponent();
	*room = section.GetRoom();
	roomConnected = section.GetConnectedRooms();
}