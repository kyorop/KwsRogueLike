#pragma once
#include "IGameProcess.h"
#include "IImageAcceptor.h"
#include "vector_2d.h"

struct ObjDataOnTile;
class Meat;
class Vector2;

class ItemManager
	:public IGameProcess, public IImageAcceptor
{
public:
	explicit ItemManager(KwsRogueLike::vector_2d<ObjDataOnTile> infos);

	void Initialize() override;
	void Finalize() override;
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	void Update(GameManager* game) override;
private:
	std::vector<std::shared_ptr<Meat>> meats;
	std::vector<std::shared_ptr<Meat>>::iterator FindSamePosItem(const Vector2& playerCoord);
};
