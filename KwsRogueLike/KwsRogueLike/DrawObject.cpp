#include "DrawObject.h"

bool DrawObject::IsVisible()
{
	return isVisible;
}

bool DrawObject::IsDead()
{
	return isDead;
}

void DrawObject::Kill()
{
	isDead = true;
	isVisible = false;
}

void DrawObject::SetDrawFlag(bool isDrawble)
{
	this->isVisible = isDrawble;
}

void DrawObject::MakeVisible()
{
	isVisible = true;
}

void DrawObject::MakeInvisible()
{
	isVisible = false;
}