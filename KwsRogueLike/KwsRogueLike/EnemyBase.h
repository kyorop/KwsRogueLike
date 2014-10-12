#pragma once
#include "CharacterBase.h"
class EnemyBase
	:public CharacterBase
{
public:
	EnemyBase(int hp, int offense, int diffense, int moveSpeed); //レベル１のキャラクタはこちら
	EnemyBase(int hp, int offense, int diffense, int moveSpeed, int level); //レベルが１より高いキャラクタはこちら
	~EnemyBase();
};

