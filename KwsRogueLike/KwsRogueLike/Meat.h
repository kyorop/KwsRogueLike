#pragma once
#include "ObjectBase.h"
#include "IItem.h"

class Vector2;

class Meat:public ObjectBase, public IItem
{
public:
	std::string GetName() override;
	std::string GetExplanation() override;
	void GiveEffect(PlayerBase* player) override;
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Meat(const Vector2& coord)
		:ObjectBase(coord)
	{}
	~Meat(){}
private:
	int handle;
};
