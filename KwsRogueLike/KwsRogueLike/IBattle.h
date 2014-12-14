#pragma once

class IBattle
{
public:
	virtual ~IBattle(){}

	virtual bool IsStop() = 0;
	virtual bool IsAttack() = 0;
	virtual int GetAttack() = 0;
	virtual int GetDiffence() = 0;
	virtual int GetHP() = 0;
	virtual void SetHP() = 0;
	virtual int GetActionableTurn() = 0;
};