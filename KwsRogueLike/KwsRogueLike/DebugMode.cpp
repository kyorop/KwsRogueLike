#include "DebugMode.h"
#include "DxLib.h"


DebugMode::DebugMode(bool debugger)
{
}


DebugMode::~DebugMode()
{
}

void DebugModeStart()
{
	if (CheckHitKeyAll())
	{
		if ((CheckHitKey(KEY_INPUT_LCONTROL) != 0) && (CheckHitKey(KEY_INPUT_RCONTROL) != 0)
			debugger = true;
	}
}
