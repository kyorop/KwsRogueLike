

class Component
{
public:
	int i;
	int j;

public:
	Component(int i, int j);

	bool operator==(const Component& rhs);
};
