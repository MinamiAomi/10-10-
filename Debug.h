#pragma once
class Debug
{

private:
	static int mPrintNum;

public:
	static void PrintNumReset();
	static void Print(const char* format, ...);
};

