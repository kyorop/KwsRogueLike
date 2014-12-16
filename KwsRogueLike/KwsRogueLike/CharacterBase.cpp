#include "CharacterBase.h"

void CharacterBase::SetHp(int hp)
{
	this->hp=hp;
}

void CharacterBase::HpChanger(int hpChanger)
{
	this->hp += hpChanger;
}

bool CharacterBase::IsMoving() const
{
	return isMoving;
}

void CharacterBase::SetMoving(bool isMoving)
{
	this->isMoving = isMoving;
}

int CharacterBase::GetHp()
{
	return this->hp;
}

int CharacterBase::GetLevel()
{
	return this->level;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed,int level)
	:isMoving(false),
	frameCount(0)
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
	this->level = level;
}


CharacterBase::~CharacterBase()
{
}