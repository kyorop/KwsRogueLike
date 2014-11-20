#include "CharacterBase.h"


void CharacterBase::Moving(Direction direction)
{
	const int moving = 2;

	if (frameCount < 32 / moving && !isMoving && direction != STOP)
	{
		isMoving = true;
		this->direction = direction;
		frameCount = 0;
	}
	else if (frameCount >= 32 / moving && isMoving)
	{
		isMoving = false;
		frameCount = 0;
		this->direction = STOP;
	}

	if (isMoving)
	{
		switch (this->direction)
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
		case STOP: 
			break;
		}

		frameCount++;
	}
}

void CharacterBase::GetHp(int hp)
{
	this->hp=hp;
}

void CharacterBase::HpChanger(int hpChanger) //HPを回復するときは正の量、HPを減らすときは負の量を指定してください。
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

//レベル１か否かで分ける必要ない気がする

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed) //レベル１のキャラクタはこちら
	:direction(UP),
	isMoving(false),
	frameCount(0)
{
	this->hp = hp;
	this->offense = offense;
	this->diffense = diffense;
	this->moveSpeed = moveSpeed;
}

CharacterBase::CharacterBase(int hp, int offense, int diffense, int moveSpeed,int level) //レベルが１より高いキャラクタはこちら
	:direction(UP),
	isMoving(false),
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


