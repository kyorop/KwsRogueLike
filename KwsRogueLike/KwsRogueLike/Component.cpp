#include "Component.h"

Component::Component(int i, int j)
	:i(i),
	j(j)
{
}

Component::Component()
	:i(0),
	j(0)
{
}

Component::Component(Component const& component)
{
	i = component.i;
	j = component.j;
}

bool Component::operator==(Component const& rhs)const
{
	return i == rhs.i && j == rhs.j;
}

bool Component::operator!=(Component const& rhs)const
{
	return !(*this == rhs);
}

bool Component::operator<(const Component& rhs)const
{
	if (i < rhs.i)
		return true;
	
	if (i == rhs.i && j < rhs.j)
		return true;

	return false;
}