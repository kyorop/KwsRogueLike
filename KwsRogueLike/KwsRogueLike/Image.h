#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IGameProcess.h"
#include <map>

class Vector2;
class IDrawable;
struct GraphData;
struct DivGraphData;
class HandleIndexer;

class ImageManager
	:public IGameProcess
{
public:
	void Update(GameManager* game) override;

	ImageManager();
	void AddDrawObject(const std::shared_ptr<IDrawable>& drawn);
	void Initialize() override;
	void Draw();
	void Finalize() override;
	
	int LoadGraph(const std::string& imgFileAddress);
	std::vector<int> LoadDivGraph(const std::string& imgFileAddress, int allNum, int xNum, int yNum, int xSize, int ySize);

private:
	std::map<std::string, int> handleMap;
	std::map<std::string, std::vector<int>> divHandleMap;

	std::vector<std::shared_ptr<IDrawable>> drawnList;
};


class HandleIndexer
{
public:
	std::shared_ptr<IDrawable> drawnObject;

	HandleIndexer(const std::shared_ptr<IDrawable>& drawn_object, int handle_index)
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