#pragma once
#include <string>
#include "playerbase.h"

class Strings
{
public:
	Strings(int floor,PlayerBase *player);
	Strings();
	//階層とプレイヤーデータを受け取って表示
	void DisplayPlayerData(int floor, PlayerBase* player);
	~Strings();
};

