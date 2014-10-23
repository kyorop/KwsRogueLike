#pragma once 
#include <vector>

class Rect;
class Component;
class Section
{
private:
	Component* myComponent;
	Rect* room;
	std::vector<const Section*> roomConnected;
	bool hasRoom;

public:
	Section();
	~Section();

	void PutRoomMark();
	bool HasRoom();
	void SetComponent(int i, int j);
	void SetComponent(const Component& component);
	void SetRoom(int i, int j, int w, int h);
	void SetRoom(const Rect& rect);
	Rect GetRoom() const;
	void SetRoomConnected(const Section* room);
};