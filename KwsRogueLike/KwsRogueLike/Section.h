#pragma once 
#include <vector>

class Rect;
class Component;
class Section
{
private:
	Component* myComponent;
	Rect* room;
	std::vector<Component> roomConnected;
	bool hasRoom;

public:
	Section();
	~Section();

	void PutRoomMark();
	bool HasRoom();
	void SetComponent(int i, int j);
	void SetComponent(Component component);
	void SetRoom(int i, int j, int w, int h);
	void SetRoom(const Rect& rect);
	Rect GetRoom();
};