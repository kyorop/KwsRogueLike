#include "PlayerBase.h"


PlayerBase::PlayerBase(int hp,int offense, int diffense, int moveSpeed, int level)
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
	this->level = level;
}