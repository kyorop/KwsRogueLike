#include "CharacterBase.h"



void CharacterBase::GetHp(int hp)
{
	this->hp=hp;
}

void CharacterBase::HpChanger(int hpChanger) //HPを回復するときは正の量、HPを減らすときは負の量を指定してください。
{
	this->hp += hpChanger;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed) //レベル１のキャラクタはこちら
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed,int level) //レベルが１より高いキャラクタはこちら
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


