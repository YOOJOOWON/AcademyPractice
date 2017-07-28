#include <Windows.h>

//API : Application Programming Interface

HINSTANCE _hInstance;		//어플 고유번호
HWND _hWnd;					//조작질

LPTSTR _lpszClass = TEXT("Iota Team");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
		_lpszClass,
		_lpszClass,
		WS_OVERLAPPEDWINDOW,		//윈도우 창 스타일
		100,						//윈도우 시작 좌표 X
		50,							//윈도우 시작 좌표 Y
		800,						//윈도우 창 가로크기
		600,						//윈도우 창 세로크기
		NULL,						//부모 윈도우 사용여부
		(HMENU)NULL,				//메뉴 사용여부
		hInstance,					//인스턴스
		NULL);						//자식 윈도우 사용여부

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
		case WM_PAINT :
		{	
			hdc = BeginPaint(hWnd, &ps);
			
			//^^
			MoveToEx(hdc, 650, 200, NULL);
			LineTo(hdc, 675, 175);
			LineTo(hdc, 700, 200);
			MoveToEx(hdc, 725, 200, NULL);
			LineTo(hdc, 750, 175);
			LineTo(hdc, 775, 200);

			//사각형 그리는 함수
			//Rectangle
			Rectangle(hdc, 100, 300, 300, 500);
			Rectangle(hdc, 100, 300, 200, 400);
			//나중에 그린게 덮어씌운다(순서가 반대라면 작은 사각형은 안 보일 것)

			//동그라미 그리는 함수
			//Ellipse
			Ellipse(hdc, 100, 300, 300, 500);


			//도전 : 육망성 그리기

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
