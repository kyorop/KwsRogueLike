#pragma once
#include <string>

class PlayerBase;

class IItem
{
public:
	virtual ~IItem(){}
	virtual std::string GetName() = 0;
	virtual std::string GetExplanation() = 0;
	virtual void GiveEffect(PlayerBase* player) = 0;
};