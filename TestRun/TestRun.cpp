#include "stdafx.h"
#include "TestRun.h"
#include "MainWindow.h"
#include "Resource.h"

inline ATOM TestRun::MyRegisterClass()
{
	WNDCLASSEXW wcex{ sizeof wcex };
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = MainWindow::WndProc;
	wcex.hInstance = MainWindow::hInstance;
	wcex.hIcon = LoadIcon(MainWindow::hInstance, MAKEINTRESOURCE(IDI_LARGE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_MENU);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

inline BOOL TestRun::InitInstance(const int nCmdShow)
{
	MainWindow::hWndMain = CreateWindowEx(WS_EX_ACCEPTFILES, szWindowClass, windowTitle,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		HWND_DESKTOP, nullptr, MainWindow::hInstance, nullptr);
	if (!MainWindow::hWndMain) return FALSE;

	ShowWindow(MainWindow::hWndMain, SW_SHOWMAXIMIZED);
#ifdef _DEBUG
	UNREFERENCED_PARAMETER(nCmdShow);
#else
	ShowWindow(MainWindow::hWndMain, nCmdShow);
#endif
	UpdateWindow(MainWindow::hWndMain);

	return TRUE;
}

inline int TestRun::Main(const int nCmdShow)
{
	MyRegisterClass();
	if (!InitInstance(nCmdShow)) return FALSE;

	const auto hAccelTable(LoadAccelerators(MainWindow::hInstance, MAKEINTRESOURCE(IDC_MENU)));
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
		if (!TranslateAccelerator(MainWindow::hWndMain, hAccelTable, &msg)
//			and !IsDialogMessage(Controls::hDlgControls, &msg)
			)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	return static_cast<int>(msg.wParam);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int nCmdShow)
{
	MainWindow::hInstance = hInstance;
	return TestRun::Main(nCmdShow);
}