#pragma once

struct DivGraphData;
struct GraphData;

namespace DxLibWrap
{
	namespace Graphic
	{
		int LoadGraphBy(const GraphData& data);
		void LoadDivGraphBy(const DivGraphData& data, int* handle);
		void DrawDivGraphBy(const DivGraphData& data, int* handles);
		void DrawGraphBy(const GraphData& data, int handle);
	}
}