#include "Component.h"

Component::Component(int i, int j)
	:i(i),
	j(j)
{
}

bool Component::operator==(Component const& rhs)
{
	return i == rhs.i && j == rhs.j;
}