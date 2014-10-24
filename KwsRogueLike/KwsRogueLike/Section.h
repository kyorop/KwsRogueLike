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
	Component GetComponent() const;
	void SetRoom(int i, int j, int w, int h);
	void SetRoom(const Rect& rect);
	Rect GetRoom() const;
	void SetRoomConnected(const Section* room);
	bool isConnected(const Section& section);

	bool EqualTo(const Section& section)const;
	bool operator==(const Section& section);
};