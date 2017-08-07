#include "stdafx.h"

//���������� �����Ѵٸ� ������ 
HINSTANCE _hInstance;		//���� ������ȣ
HWND _hWnd;					//������

LPTSTR _lpszClass = TEXT("Iota Team");

POINT _ptMouse;
//�ϾϾ���

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
	MSG message;			//�޼���
	WNDCLASS wndClass;		//������ ������ ���� ����ü

	//Salt Bae 
	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;										//Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;										//������ ���� �޸� 
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ ��׶��� 
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//������ Ŀ��
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//������ ������
	wndClass.hInstance = hInstance;									//������ �ν��Ͻ� ��ȣ
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//������ ���ν���
	wndClass.lpszClassName = _lpszClass;							//������ Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;									//������ �޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//������ â ��Ÿ��

	//������ ���� ���
	RegisterClass(&wndClass);

	//������ â ��������
	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,		//������ â ��Ÿ��
		WINSTARTX,					//������ ���� ��ǥ X
		WINSTARTY,					//������ ���� ��ǥ Y
		WINSIZEX,					//������ â ����ũ��
		WINSIZEY,					//������ â ����ũ��
		NULL,						//�θ� ������ ��뿩��
		(HMENU)NULL,				//�޴� ��뿩��
		hInstance,					//�ν��Ͻ�
		NULL);						//�ڽ� ������ ��뿩��

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//������ â�� ����Ϳ� �����
	ShowWindow(_hWnd, cmdShow);

	//GetMessage : �޽��� ������ ������ �׶� ����
	//PeekMessage : �޽��� ������ ������ ���� ������ ����(��� ������������)
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//�Է��� ������ ���� �� �޽��� ó�� ���
		DispatchMessage(&message);	//������ �����쿡 �� �޽��� ����
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
		//������ â�� �������� ������ �Ǵ� �Լ�
		case WM_CREATE:
			
		break;


		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);

			char str[64];
			char str2[64];
			sprintf_s(str, "�ڽ���ǥ X : %d, Y : %d", _ptBox.x, _ptBox.y);
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
			//������ â ���� �Լ�
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
