#include<windows.h>

BOOL WINAPI DllMain(HINSTANCE hDll, 
					DWORD dwReason,
					LPVOID lpvReserved)
{
	switch(dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) int MakeSquare(int iNum)
{
	return (iNum*iNum);
}
extern "C" BOOL IsNumberNegative(int iNum)
{
	if(iNum < 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}