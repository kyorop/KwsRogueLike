#include "CharacterBase.h"

void CharacterBase::GetHp(int hp)
{
	this->hp=hp;
}

void CharacterBase::HpChanger(int hpChanger) //HP���񕜂���Ƃ��͐��̗ʁAHP�����炷�Ƃ��͕��̗ʂ��w�肵�Ă��������B
{
	this->hp += hpChanger;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed) //���x���P�̃L�����N�^�͂�����
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed,int level) //���x�����P��荂���L�����N�^�͂�����
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

void CharacterBase::Damage(int damage)
{

}