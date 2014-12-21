#pragma once
#include <vector>
#include <memory>

class IDrawable;

namespace KwasRogueLike
{
	namespace Util
	{
		namespace Image
		{
			void DoHeapSort(std::vector<std::shared_ptr<IDrawable>>& list);
		}
	}	
}
