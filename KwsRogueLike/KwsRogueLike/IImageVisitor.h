#pragma once
#include <memory>

class IDrawable;

class IImageVisitor
{
public:
	void visit(std::shared_ptr<IDrawable> drawn);
};