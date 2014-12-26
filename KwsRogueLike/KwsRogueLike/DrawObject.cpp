#include "DrawObject.h"

bool DrawObject::GetDrawFlag()
{
	return isDrawable;
}

bool DrawObject::IsDead()
{
	return isDead;
}

void DrawObject::SetDrawFlag(bool isDrawble)
{
	this->isDrawable = isDrawble;
}

void DrawObject::Kill()
{
	isDead = true;
}