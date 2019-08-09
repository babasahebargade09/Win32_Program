/*! \brief

Windows Programming by using c++.

--------------------------------------------------------------------

PROJECT         : 

FILE            : 

AUTHOR          : Babasaheb argade

CREATION DATE   : 2019-07-08

COMPILER        : VC

HW PLATFORM     : PC

OPERATING-SYS   : None

--------------------------------------------------------------------
*/
#include<windows.h>

//global funtion declaration

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//Entry point funtion WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration 
	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//Step
	//initialize the window class.
	//registern window class
	//create the window in memory
	//show the window on desktop.
	//paint backgrount of the window.
	//Write the message loop.
	//Define Window callback procedure
	//inside it atleast one compulsory msg handler.
	//divert all the reamaining msg to windowse OS


	//1.initialize the window class
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style  = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(NULL,IDI_APPLICATION);


	//Register above class

	RegisterClassEx(&wndClass);

	//create the window in memory.

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

	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);

	//Message loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd , UINT iMsg , WPARAM wParam, LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}
