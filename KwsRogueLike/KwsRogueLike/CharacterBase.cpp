#include "CharacterBase.h"

void CharacterBase::SetHp(int hp) //get����Ȃ���set����ˁH���Ă��Ƃŕς���
{
	this->hp=hp;
}

void CharacterBase::HpChanger(int hpChanger) //HP���񕜂���Ƃ��͐��̗ʁAHP�����炷�Ƃ��͕��̗ʂ��w�肵�Ă��������B
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

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed,int level) //���x�����P��荂���L�����N�^�͂�����
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


