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

bool Component::operator==(Component const& rhs)
{
	return i == rhs.i && j == rhs.j;
}

bool Component::operator!=(Component const& rhs)
{
	return !(*this == rhs);
}