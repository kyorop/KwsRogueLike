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

		void LoadDivGraphBy(const DivGraphData& data, int* handle)
		{
			LoadDivGraph(data.address.data(),
				data.allNum,
				data.xNum,
				data.yNum,
				data.xSize,
				data.ySize,
				handle, true);
		}

		void DrawDivGraphBy(const DivGraphData& data, int* handles)
		{
			DrawGraph(data.x, data.y, handles[data.animationHandle], data.transFlag);
		}

		void DrawGraphBy(const GraphData& data, int handle)
		{
			DrawGraph(data.x, data.y, handle, data.transFlag);
		}
	}	
}