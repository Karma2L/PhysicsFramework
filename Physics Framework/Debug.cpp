#include "Debug.h"

void Debug::debugLog(float t)
{
	char sz[1024] = { 0 };
	sprintf_s(sz, "the number is %f \n", t);
	OutputDebugStringA(sz);
}

void Debug::debug()
{
	OutputDebugStringA("Key 1 has been pressed \n");
}
