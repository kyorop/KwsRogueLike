#pragma once
#include <vector>
#include <memory>

class IDrawable;

namespace KwsRogueLike
{
	namespace Util
	{
		namespace Image
		{
			void DoHeapSort(std::vector<std::shared_ptr<IDrawable>>& list);
		}
	}	
}
