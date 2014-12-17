#pragma once
#include <memory>

class ImageManager;
class IImageAcceptor
{
public:
	virtual ~IImageAcceptor()
	{
	}

	virtual void Accept(const std::shared_ptr<ImageManager>& image) const = 0;
};