#pragma once
class DebugMode
{
private:
	bool debugger = false;
public:
	DebugMode(bool debugger);
	~DebugMode();
	void StartDebugMode();
};

