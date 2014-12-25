#pragma once
#include <memory>
#include "IDrawable.h"

class Screen;
class Vector2;
class ObjectBase:public IDrawable
{
public:
	bool GetDrawFlag() override;
	ObjectBase();
	explicit ObjectBase(const Vector2& coord);
	virtual ~ObjectBase();

private:
	std::shared_ptr<Vector2> coordinate;
	bool drawFlag;
	bool isDead;

public:
	void SetCoordinate(int x, int y);
	void SetCoordinate(const Vector2& coordinate);
	virtual Vector2 GetCoordinate()const;
	void AddCoordinate(int x, int y);
	void AddCoordinate(const Vector2& v);
	virtual Vector2 GetDrawCoord();
	size_t Get_i();
	size_t Get_j();
	void SetDrawFlag(bool flag);
	bool IsDead() override;
	void Kill();
};

