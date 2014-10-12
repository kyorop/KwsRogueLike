#include "PlayerBase.h"


PlayerBase::PlayerBase(int hp, int offense, int diffense, int moveSpeed)
	:CharacterBase(hp, offense, diffense, offense, moveSpeed)
{
}


PlayerBase::~PlayerBase()
{
}
