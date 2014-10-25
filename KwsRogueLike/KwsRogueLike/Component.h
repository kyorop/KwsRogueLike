

class Component
{
public:
	int i;
	int j;

public:
	Component(int i, int j);
	Component();
	Component(const Component&);

	bool operator==(const Component& rhs);
};
