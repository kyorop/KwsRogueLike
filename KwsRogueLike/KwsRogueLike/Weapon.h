#pragma once
#include "ItemBase.h"
#include "IEquipable.h"

class Weapon
	:public ItemBase, virtual public IEquipable
{
public:
	Weapon();
	~Weapon();
};

