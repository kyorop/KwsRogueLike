#pragma once
#include <vector>
#include <memory>
#include "IGameProcess.h"

struct GraphData;
struct DivGraphData;
class HandleIndexer;
class IDrawObject;

class ImageManager
	:public IGameProcess
{
public:
	void Update(std::shared_ptr<GameManager> game) const override;

	ImageManager(){}

	void SetDrawnObject(std::shared_ptr<IDrawObject> drawn);
	void Draw();
	void Finalize();

private:
	std::vector<int> handleList;
	std::vector<std::vector<int>> divHandleList;
	std::vector<std::shared_ptr<HandleIndexer>> drawnList;
	void Initialize(std::shared_ptr<IDrawObject> drawn);
};


class HandleIndexer
{
public:
	std::shared_ptr<IDrawObject> drawnObject;

	HandleIndexer(const std::shared_ptr<IDrawObject>& drawn_object, int handle_index)
		: drawnObject(drawn_object),
		  handleIndex(handle_index)
	{
	}

	int GetIndex() const
	{
		return handleIndex;
	}

private:
	int handleIndex;
};