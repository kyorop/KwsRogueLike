#include "DxLibGraphic.h"
#include <DxLib.h>
#include "IDrawObject.h"

namespace DxLibWrap
{
	namespace Graphic
	{
		int LoadGraphBy(const GraphData& data)
		{
			return LoadGraph(data.address.data(), true);
		}

		void LoadDivGraphBy(const GraphData& data, const DivGraphData& divData, int* handle)
		{
			LoadDivGraph(data.address.data(), divData.allNum, divData.xNum, divData.yNum, divData.xSize, divData.ySize, handle);
		}

		void DrawGraphBy(const GraphData& data, int handle)
		{
			DrawGraph(data.x, data.y, handle, data.transFlag);
		}
	}	
}