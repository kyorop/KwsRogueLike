#pragma once
#include "CharacterBase.h"
class EnemyBase
	:public CharacterBase
{
public:
	EnemyBase(int hp, int offense, int diffense, int moveSpeed); //���x���P�̃L�����N�^�͂�����
	EnemyBase(int hp, int offense, int diffense, int moveSpeed, int level); //���x�����P��荂���L�����N�^�͂�����
	~EnemyBase();
};

