#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IGameProcess.h"
#include <map>
#include <list>

class Vector2;
class IDrawable;
struct GraphData;
struct DivGraphData;
class HandleIndexer;

class ImageManager
	:public IGameProcess
{
public:
	void Update(GameManager* game) const override;

	ImageManager();
	void SetDrawnObject(const std::shared_ptr<IDrawable>& drawn);
	void Initialize();
	void Draw();
	void Finalize();
	
	int LoadGraph(const std::string& imgFileAddress);
	std::vector<int> LoadDivGraph(const std::string& imgFileAddress, int allNum, int xNum, int yNum, int xSize, int ySize);
private:
	std::vector<int> handleList;
	std::vector<std::shared_ptr<IDrawable>> drawnList;
	std::shared_ptr<Vector2> screenCoord;
	std::map<std::string, int> loadedImg;

	void SortDrawnList(std::vector<std::shared_ptr<IDrawable>>& list);
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