#pragma once
#include <memory>

class ImageManager;
class IImageAcceptor
{
public:
	virtual ~IImageAcceptor()
	{
	}

	virtual void Accept(std::shared_ptr<ImageManager> image)const = 0;
};