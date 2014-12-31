#pragma once
#include <vector>

enum class ObjTypeOnMap;

class DebugMode
{
public:
	DebugMode();
	~DebugMode();
	void StartDebugMode(std::vector<std::vector<ObjTypeOnMap>>* map);
};

