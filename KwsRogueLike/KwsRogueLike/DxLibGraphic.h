#pragma once

struct DivGraphData;
struct GraphData;

namespace DxLibWrap
{
	namespace Graphic
	{
		int LoadGraphBy(const GraphData& data);
		void LoadDivGraphBy(const GraphData& data, const DivGraphData& divData, int* handle);
		void DrawGraphBy(const GraphData& data, int handle);
	}
}