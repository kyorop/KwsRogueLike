#pragma once
#include "IGameProcess.h"
#include "IImageAcceptor.h"
#include "vector_2d.h"

struct MapInformation;
class Meat;

class ItemManager
	:public IGameProcess, public IImageAcceptor
{
public:
	void CreateItem(KwsRogueLike::vector_2d<MapInformation> infos);
	void Accept(const std::shared_ptr<ImageManager>& image) const override;
	void Update(GameManager* game) override;
private:
	std::vector<std::shared_ptr<Meat>> meats;
};
