#include<windows.h>
#include"MyMath.h"

#pragma comment(lib,"MyMath.lib")//this line is import library file
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
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
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
	int i , j;
	TCHAR str[255];
	switch(iMsg)
	{
	case WM_CREATE:
		i = 25;
		j = MakeSquare(i);
		wsprintf(str,TEXT("Sqaure of %d  is %d "),i,j);
		MessageBox(hwnd,str,TEXT("Alert"),MB_OK | MB_ICONINFORMATION);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd,iMsg,wParam,lParam));}

