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
	Section(const Section& section);
	~Section();

	void PutRoomMark();
	bool HasRoom()const;
	void SetComponent(int i, int j);
	void SetComponent(const Component& component);
	Component GetComponent() const;
	void SetRoom(int i, int j, int w, int h);
	void SetRoom(const Rect& rect);
	Rect GetRoom() const;
	void SetRoomConnected(Section* room);
	std::vector<const Section*> GetConnectedRooms()const;
	bool isConnectedTo(const Section& section)const;

	bool EqualTo(const Section& section)const;
	bool operator==(const Section& section);
	void operator=(const Section& section);
};