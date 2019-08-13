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

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX Wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Windows");

	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = AppName;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	Wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	Wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	Wndclass.hInstance = hInstance;
	Wndclass.hIconSm = LoadIcon(NULL , IDI_APPLICATION);
	Wndclass.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&Wndclass);

	
	hwnd = CreateWindow(AppName,
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

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd , UINT iMsg, WPARAM wParam , LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	switch(iMsg)
	{
	case WM_PAINT:
		{
			GetClientRect(hwnd,&rc);
			hdc = BeginPaint(hwnd, &ps);

			//Set Text Colour
			SetTextColor(hdc, RGB(0,255,0));
			SetBkColor(hdc,RGB(0,0,0));
			DrawText(hdc,
				TEXT("Hello World"),
				-1,
				&rc,
				DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint(hwnd,&ps);

			break;
		}
	}

	return (DefWindowProc(hwnd,iMsg,wParam,lParam));
}
