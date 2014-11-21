#include <string>
#include "playerbase.h"
#pragma once

class Strings
{
public:
	Strings(int floor,PlayerBase *player);
	Strings();
	//階層とプレイヤーデータを受け取って表示
	void DisplayPlayerData(int floor, PlayerBase* player);
	~Strings();
};

