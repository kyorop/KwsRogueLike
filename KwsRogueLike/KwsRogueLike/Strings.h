#pragma once
#include <string>
#include "playerbase.h"

class Strings
{
public:
	Strings(int floor,PlayerBase *player);
	Strings();
	//�K�w�ƃv���C���[�f�[�^���󂯎���ĕ\��
	void DisplayPlayerData(int floor, PlayerBase* player);
	~Strings();
};

