#pragma once

class IAttack
{
public:
	virtual ~IAttack(){};
	virtual void attack() = 0;
};