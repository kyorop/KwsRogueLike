#include "CharacterBase.h"


void CharacterBase::Moving()
{
	const int moving = 2;
	if (frameCount < 32/moving)
	{
		switch (direction)
		{
		case UP:
			AddCoordinate(0, -moving);
			break;
		case UPRIGHT:
			AddCoordinate(moving, -moving);
			break;
		case RIGHT:
			AddCoordinate(moving, 0);
			break;
		case DOWNRIGHT:
			AddCoordinate(moving, moving);
			break;
		case DOWN:
			AddCoordinate(0, moving);
			break;
		case DOWNLEFT:
			AddCoordinate(-moving, moving);
			break;
		case LEFT:
			AddCoordinate(-moving, 0);
			break;
		case UPLEFT:
			AddCoordinate(-moving, -moving);
			break;
		default: break;
		}

		frameCount++;
	}
	else
	{
		frameCount = 0;
		isMoving = false;
	}
}

void CharacterBase::GetHp(int hp)
{
	this->hp=hp;
}

void CharacterBase::HpChanger(int hpChanger) //HP���񕜂���Ƃ��͐��̗ʁAHP�����炷�Ƃ��͕��̗ʂ��w�肵�Ă��������B
{
	this->hp += hpChanger;
}

CharacterBase::Direction CharacterBase::GetDirection() const
{
	return direction;
}

bool CharacterBase::IsMoving() const
{
	return isMoving;
}

void CharacterBase::SetMoving(bool isMoving)
{
	this->isMoving = isMoving;
}

void CharacterBase::SetDirection(Direction direction)
{
	this->direction = direction;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed) //���x���P�̃L�����N�^�͂�����
	:direction(UP),
	isMoving(false)
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed,int level) //���x�����P��荂���L�����N�^�͂�����
	:direction(UP),
	isMoving(false)
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


