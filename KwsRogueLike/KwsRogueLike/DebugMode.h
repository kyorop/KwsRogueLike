#pragma once
#include <vector>

enum class ObjectTypeOnMap;

class DebugMode
{
public:
	DebugMode();
	~DebugMode();
	void StartDebugMode(std::vector<std::vector<ObjectTypeOnMap>>* map);
};

