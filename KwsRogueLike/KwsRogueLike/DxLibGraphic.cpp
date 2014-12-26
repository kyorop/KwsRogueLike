#include "DxLibGraphic.h"
#include "DxLib.h"

void KwsRogueLike::Util::DeleteGraph(std::vector<int>& divHandles)
{
	for (int handle : divHandles)
	{
		DxLib::DeleteGraph(handle);
	}
	divHandles.clear();
}