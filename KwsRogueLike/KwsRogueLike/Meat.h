#pragma once
#include "IItem.h"
#include "DrawObject.h"

class Vector2;

class Meat:public DrawObject, public IItem
{
public:
	std::string GetName() override;
	std::string GetExplanation() override;
	void GiveEffect(PlayerBase* player) override;
	int GetLayer() override;
	void Load(ImageManager* manager) override;
	void Draw(ImageManager* manager) override;

	explicit Meat(const Vector2& coord)
		:DrawObject(coord)
	{}
	~Meat(){}
private:
	int handle;
};
