/*! \brief

Windows Programming by using c++.

--------------------------------------------------------------------

PROJECT         : 

FILE            : 

AUTHOR          : Babasaheb argade

CREATION DATE   : 2019-07-08

COMPILER        : VC

HW PLATFORM     : PC

OPERATING-SYS   : Windows NT Family.

--------------------------------------------------------------------
*/

//Header file
#include<windows.h> 

//global function declaration.
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//Enrty point funtion WinMain()
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpszCMDLine, int iCmdshow)
{
	//varible declaration

	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//initilization of wndClassex

	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style  = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndClass);

	//create Window
	hwnd = CreateWindow(szAppName,
			TEXT("My Application"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			hInstance,
			NULL
		);

	ShowWindow(hwnd,iCmdshow);
	UpdateWindow(hwnd);

	//message loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd , UINT iMsg , WPARAM wParam , LPARAM lParam)
{
	switch(iMsg)
	{
		TCHAR str[255];
	case WM_CREATE:
		MessageBox(NULL,(LPCWSTR)L"First Window is Comming",(LPCWSTR)L"Alert",MB_OK);
		break;
	case WM_KEYDOWN:
		wsprintf(str,TEXT("please Don't Enter KeyBoard Key"));
		MessageBox(hwnd,str,TEXT("Alert"),MB_OK | MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
} 
