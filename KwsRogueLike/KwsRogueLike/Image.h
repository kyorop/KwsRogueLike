#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IGameProcess.h"

class Vector2;
class IDrawable;
struct GraphData;
struct DivGraphData;
class HandleIndexer;

class ImageManager
	:public IGameProcess
{
public:
	void Update(std::shared_ptr<GameManager> game) const override;

	ImageManager();
	void SetDrawnObject(IDrawable* drawn);
	void Initialize();
	void Draw();
	void Finalize();
	
	int LoadGraph(const std::string& imgFileAddress);
	std::vector<int> LoadDivGraph(const std::string& imgFileAddress, int allNum, int xNum, int yNum, int xSize, int ySize);
	Vector2 SolveDrawCoord(const Vector2& gameCoord);
private:
	std::vector<int> handleList;
	std::vector<IDrawable*> drawnList;
	std::shared_ptr<Vector2> screenCoord;
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