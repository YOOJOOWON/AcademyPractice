#include <Windows.h>

//API : Application Programming Interface

HINSTANCE _hInstance;		//���� ������ȣ
HWND _hWnd;					//������

LPTSTR _lpszClass = TEXT("Iota Team");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
		_lpszClass,
		_lpszClass,
		WS_OVERLAPPEDWINDOW,		//������ â ��Ÿ��
		100,						//������ ���� ��ǥ X
		50,							//������ ���� ��ǥ Y
		800,						//������ â ����ũ��
		600,						//������ â ����ũ��
		NULL,						//�θ� ������ ��뿩��
		(HMENU)NULL,				//�޴� ��뿩��
		hInstance,					//�ν��Ͻ�
		NULL);						//�ڽ� ������ ��뿩��

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
		case WM_PAINT :
		{	
			hdc = BeginPaint(hWnd, &ps);
			//�̸�����
			//��
			//��
			MoveToEx(hdc, 100, 100, NULL);
			LineTo(hdc, 150, 100);
			LineTo(hdc, 200, 130);
			LineTo(hdc, 150, 160);
			LineTo(hdc, 100, 160);
			LineTo(hdc, 50, 130);
			LineTo(hdc, 100, 100);
			
			//��
			MoveToEx(hdc, 50, 200, NULL);
			LineTo(hdc, 200, 200);

			MoveToEx(hdc, 100, 200, NULL);
			LineTo(hdc, 100, 250);

			MoveToEx(hdc, 150, 200, NULL);
			LineTo(hdc, 150, 250);

			//��
			//��
			MoveToEx(hdc, 250, 100, NULL);
			LineTo(hdc, 400, 100);
			MoveToEx(hdc, 325, 100, NULL);
			LineTo(hdc, 250, 150);
			MoveToEx(hdc, 325, 100, NULL);
			LineTo(hdc, 400, 150);

			//��
			MoveToEx(hdc, 250, 200, NULL);
			LineTo(hdc, 400, 200);
			MoveToEx(hdc, 325, 200, NULL);
			LineTo(hdc, 325, 250);

			//��
			//��
			MoveToEx(hdc, 500, 100, NULL);
			LineTo(hdc, 550, 100);
			LineTo(hdc, 600, 130);
			LineTo(hdc, 550, 160);
			LineTo(hdc, 500, 160);
			LineTo(hdc, 450, 130);
			LineTo(hdc, 500, 100);

			//��
			MoveToEx(hdc, 450, 180, NULL);
			LineTo(hdc, 600, 180);
			MoveToEx(hdc, 525, 180, NULL);
			LineTo(hdc, 525, 230);

			//��
			MoveToEx(hdc, 570, 205, NULL);
			LineTo(hdc, 625, 205);
			MoveToEx(hdc, 625, 100, NULL);
			LineTo(hdc, 625, 230);
			
			//��
			MoveToEx(hdc, 550, 200, NULL);
			LineTo(hdc, 550, 250);
			LineTo(hdc, 625, 250);

			//^^
			MoveToEx(hdc, 650, 200, NULL);
			LineTo(hdc, 675, 175);
			LineTo(hdc, 700, 200);
			MoveToEx(hdc, 725, 200, NULL);
			LineTo(hdc, 750, 175);
			LineTo(hdc, 775, 200);

			//�簢�� �׸��� �Լ�
			//Rectangle
			Rectangle(hdc, 100, 300, 300, 500);
			Rectangle(hdc, 100, 300, 200, 400);
			//���߿� �׸��� ������(������ �ݴ��� ���� �簢���� �� ���� ��)

			//���׶�� �׸��� �Լ�
			//Ellipse
			Ellipse(hdc, 100, 300, 300, 500);


			//���� : ������ �׸���

			Ellipse(hdc, 50, 50, 550, 550);
			Ellipse(hdc, 100, 100, 500, 500);
			MoveToEx(hdc, 300, 100, NULL);
			LineTo(hdc, 127, 400);
			LineTo(hdc, 473, 400);
			LineTo(hdc, 300, 100);
			MoveToEx(hdc, 300, 500, NULL);
			LineTo(hdc, 127, 200);
			LineTo(hdc, 473, 200);
			LineTo(hdc, 300, 500);

			MoveToEx(hdc, 550, 400, NULL);
			LineTo(hdc, 550, 550);
			LineTo(hdc, 750, 550);
			LineTo(hdc, 750, 400);
			LineTo(hdc, 550, 400);
			
			MoveToEx(hdc, 600, 450, NULL);
			LineTo(hdc, 630, 450);
			LineTo(hdc, 630, 480);
			LineTo(hdc, 600, 480);
			LineTo(hdc, 600, 450);

			MoveToEx(hdc, 700, 450, NULL);
			LineTo(hdc, 670, 450);
			LineTo(hdc, 670, 480);
			LineTo(hdc, 700, 480);
			LineTo(hdc, 700, 450);
			
			MoveToEx(hdc, 650, 500, NULL);
			LineTo(hdc, 620, 520);
			LineTo(hdc, 680, 520);
			LineTo(hdc, 650, 500);

			//HBRUSH
			//SelectObject

			EndPaint(hWnd, &ps);
		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}