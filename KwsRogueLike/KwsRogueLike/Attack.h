#pragma once

class Attack
{
public:
	virtual ~Attack(){};

	virtual void cAttack() = 0;
};