#include "stdafx.h"

//전역변수를 선언한다면 요기요기요 
HINSTANCE _hInstance;		//어플 고유번호
HWND _hWnd;					//조작질

LPTSTR _lpszClass = TEXT("Iota Team");

POINT _ptMouse;
//하암쑤우

POINT _ptBox = { 100,100 };
POINT _ptBox2 = { 200,200 };
bool isClicked = false;
bool isClicked2 = false;
int tempX, tempY;
int temp2X, temp2Y;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	MSG message;			//메세지
	WNDCLASS wndClass;		//윈도우 정보를 담을 구조체

	//Salt Bae 
	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;										//클래스 여분 메모리
	wndClass.cbWndExtra = 0;										//윈도우 여분 메모리 
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우 백그라운드 
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//윈도우 커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//윈도우 아이콘
	wndClass.hInstance = hInstance;									//윈도우 인스턴스 번호
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//윈도우 프로시져
	wndClass.lpszClassName = _lpszClass;							//윈도우 클래스 이름
	wndClass.lpszMenuName = NULL;									//윈도우 메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//윈도우 창 스타일

	//윈도우 정보 등록
	RegisterClass(&wndClass);

	//윈도우 창 생성정보
	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,		//윈도우 창 스타일
		WINSTARTX,					//윈도우 시작 좌표 X
		WINSTARTY,					//윈도우 시작 좌표 Y
		WINSIZEX,					//윈도우 창 가로크기
		WINSIZEY,					//윈도우 창 세로크기
		NULL,						//부모 윈도우 사용여부
		(HMENU)NULL,				//메뉴 사용여부
		hInstance,					//인스턴스
		NULL);						//자식 윈도우 사용여부

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//윈도우 창을 모니터에 띄워줌
	ShowWindow(_hWnd, cmdShow);

	//GetMessage : 메시지 정보가 들어오면 그때 반응
	//PeekMessage : 메시지 정보가 들어오든 말든 무조건 반응(상시 루프돌고있음)
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//입력이 들어오는 순간 그 메시지 처리 담당
		DispatchMessage(&message);	//실제로 윈도우에 그 메시지 전달
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
		//윈도우 창이 켜질때만 실행이 되는 함수
		case WM_CREATE:
			
		break;


		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);

			char str[64];
			char str2[64];
			sprintf_s(str, "박스좌표 X : %d, Y : %d", _ptBox.x, _ptBox.y);
			sprintf_s(str2, "%d", isClicked);
			TextOut(hdc, 50, 50, str, strlen(str));
			TextOut(hdc, 50, 100, str2, strlen(str2));

			RectangleMake(hdc, _ptBox.x, _ptBox.y, 100, 100);
			RectangleMake(hdc, _ptBox2.x, _ptBox2.y, 100, 100);

			EndPaint(hWnd, &ps);
		}
		break;

		case WM_LBUTTONDOWN:
			_ptMouse.x = LOWORD(lParam);
			_ptMouse.y = HIWORD(lParam);
			if ((_ptMouse.x > _ptBox.x) && (_ptMouse.x < _ptBox.x + 100) && (_ptMouse.y > _ptBox.y) && (_ptMouse.y < _ptBox.y + 100)) {
				tempX = _ptMouse.x - _ptBox.x;
				tempY = _ptMouse.y - _ptBox.y;
				isClicked = true;
			}
			if ((_ptMouse.x > _ptBox2.x) && (_ptMouse.x < _ptBox2.x + 100) && (_ptMouse.y > _ptBox2.y) && (_ptMouse.y < _ptBox2.y + 100)) {
				temp2X = _ptMouse.x;
				temp2Y = _ptMouse.y;
				isClicked2 = true;
			}

		break;

		case WM_MOUSEMOVE:
			if (isClicked) {
				_ptBox.x = LOWORD(lParam) - tempX;
				_ptBox.y = HIWORD(lParam) - tempY;
				InvalidateRect(_hWnd, NULL, true);
			}
			if (isClicked2) {
				setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX + (LOWORD(lParam) - temp2X) , WINSIZEY + (HIWORD(lParam) - temp2Y));

			}
		break;

		case WM_LBUTTONUP:
			isClicked = false; 
			isClicked2 = false;
			InvalidateRect(_hWnd, NULL, true);
			break;

		case WM_DESTROY:
			//윈도우 창 종료 함수
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;
	
	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);

}
