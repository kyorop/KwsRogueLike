#pragma once 
#include <vector>

class Rect;
class Component;
class Section
{
private:
	Component* myComponent;
	Rect* room;
	std::vector<Section*> roomConnected;
	bool hasRoom;
	int groupId;

public:
	int GetGroupId() const
	{
		return groupId;
	}

public:
	Section();
	Section(const Section& section);
	~Section();
	bool operator==(const Section& section);
	void operator=(const Section& section);

private:
	void RemoveRoom(Section* section);

public:
	bool HasRoom()const;
	void SetComponent(int i, int j);
	void SetComponent(const Component& component);
	Component GetComponent() const;
	void SetRoom(int i, int j, int w, int h);
	void SetRoom(const Rect& rect);
	void RemoveRoom();
	Rect GetRoom() const;
	void SetRoomConnected(Section* room);
	std::vector<Section*> GetConnectedRooms()const;
	bool isConnectedTo(const Section& section)const;
	std::vector<Section*> SetGroupId(const int id);

	bool EqualTo(const Section& section)const;
};