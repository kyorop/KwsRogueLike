#include "IDrawObject.h"
#include <DxLib.h>

GraphData IDrawObject::GetGraphData() const
{
	GraphData data("",0,0,0);
	return data;
}


DivGraphData IDrawObject::GetDivGraphData()const
{
	return DivGraphData(0,0,0,0,0,0);
}