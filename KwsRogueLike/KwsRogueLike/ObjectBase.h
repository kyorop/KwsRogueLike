#pragma once
#include <memory>

class Screen;
class Vector2;
class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase();

private:
	std::shared_ptr<Vector2> coordinate;
	int layer;

public:
	void SetCoordinate(int x, int y);
	void SetCoordinate(const Vector2& coordinate);
	Vector2 GetCoordinate()const;
	void AddCoordinate(int x, int y);
	void AddCoordinate(const Vector2& v);

	virtual void Draw(){}//ˆêŽž“I‚ÉObjectBase‚ÉŽÀ‘•
	virtual void Draw(const Screen& screen);
};

