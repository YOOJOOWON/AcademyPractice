#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{

}

//초기화
HRESULT mainGame::init(void)
{
	gameNode::init();

	_player1.rc = RectMakeCenter(WINSIZEX / 2 - 400, WINSIZEY / 2, 100, 50);
	_player2.rc = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2, 100, 50);

	_player1.mode = MODE_NORMAL;
	_player2.mode = MODE_NORMAL;

	_player1.specialEnable = false;
	_player2.specialEnable = false;
	_player1.specialCount = 1;
	_player2.specialCount = 1;

	_obstacle[0].rc = RectMakeCenter(WINSIZEX / 2 - 100, WINSIZEY / 2, 50, 150);
	_obstacle[1].rc = RectMakeCenter(WINSIZEX / 2 + 100, WINSIZEY / 2, 50, 100);
	_obstacle[0].moveUp = true;
	_obstacle[1].moveUp = false;
	_obstacle[0].speed = 3;
	_obstacle[1].speed = 6;

	_area1 = RectMakeCenter(WINSIZEX / 2 - 400, WINSIZEY / 2, WINSIZEX / 2 - 300, WINSIZEY);
	_area2 = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2, WINSIZEX / 2 - 300, WINSIZEY);


	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet1[i].isFire = false;
		_bullet1[i].speed = 10;
		_bullet1[i].isGuided = false;
		_bullet2[i].isFire = false;
		_bullet2[i].speed = 10;
		_bullet2[i].isGuided = false;
	}

	_Gauge1Bottom = RectMakeCenter(WINSIZEX / 2 - 300, 50, 500, 50);
	_Gauge1Top = RectMakeCenter(WINSIZEX / 2 - 300, 50, 500, 50);
	_Gauge2Bottom = RectMakeCenter(WINSIZEX / 2 + 300, 50, 500, 50);
	_Gauge2Top = RectMakeCenter(WINSIZEX / 2 + 300, 50, 500, 50);

	_r1 = 0;
	_g1 = 240;
	_r2 = 0;
	_g2 = 240;
	_r3 = 100;
	_r4 = 100;

	_SpecialAlarm1 = RectMakeCenter(WINSIZEX / 2 - 400, 93, 30, 30);
	_SpecialAlarm2 = RectMakeCenter(WINSIZEX / 2 + 400, 93, 30, 30);

	_isStart = false;
	_isGameOver = false;

	countdown = 4.0;
	sprintf_s(str, "countdown : %d", static_cast<int>(countdown));

	sprintf_s(str1, "MODE : NORMAL");
	sprintf_s(str2, "MODE : NORMAL");

	return S_OK;
}
//메모리 해제
void mainGame::release(void)
{

}

//연산관련(타이머)
void mainGame::update(void)	
{
	gameNode::update();

	if (!_isStart) {
		if (countdown > 1) {
			countdown -= 0.02;
			sprintf_s(str, "countdown : %d", static_cast<int>(countdown));
		}
		else
		{
			sprintf_s(str, "");
			_isStart = true;
		}
	}

	if (_isStart && (!_isGameOver)) {
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_player1.rc.top -= 5;
			_player1.rc.bottom -= 5;
			if (_player1.rc.top < _area1.top) {
				_player1.rc.bottom = _area1.top + 50;
				_player1.rc.top = _area1.top;
			}
		}

		if (KEYMANAGER->isStayKeyDown('S'))
		{
			_player1.rc.top += 5;
			_player1.rc.bottom += 5;
			if (_player1.rc.bottom > _area1.bottom) {
				_player1.rc.bottom = _area1.bottom;
				_player1.rc.top = _area1.bottom - 50;
			}
		}
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_player1.rc.left -= 5;
			_player1.rc.right -= 5;
			if (_player1.rc.left < _area1.left) {
				_player1.rc.left = _area1.left;
				_player1.rc.right = _area1.left + 100;
			}
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_player1.rc.left += 5;
			_player1.rc.right += 5;
			if (_player1.rc.right > _area1.right) {
				_player1.rc.right = _area1.right;
				_player1.rc.left = _area1.right - 100;
			}
		}

		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_player2.rc.top -= 5;
			_player2.rc.bottom -= 5;
			if (_player2.rc.top < _area2.top) {
				_player2.rc.bottom = _area2.top + 50;
				_player2.rc.top = _area2.top;
			}
		}

		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_player2.rc.top += 5;
			_player2.rc.bottom += 5;
			if (_player2.rc.bottom > _area2.bottom) {
				_player2.rc.bottom = _area2.bottom;
				_player2.rc.top = _area2.bottom - 50;
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player2.rc.left -= 5;
			_player2.rc.right -= 5;
			if (_player2.rc.left < _area2.left) {
				_player2.rc.left = _area2.left;
				_player2.rc.right = _area2.left + 100;
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player2.rc.left += 5;
			_player2.rc.right += 5;
			if (_player2.rc.right > _area2.right) {
				_player2.rc.right = _area2.right;
				_player2.rc.left = _area2.right - 100;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('1')) {
			_player1.mode = MODE_NORMAL;
			sprintf_s(str1, "MODE : NORMAL");
		}
		if (KEYMANAGER->isOnceKeyDown('2')) {
			_player1.mode = MODE_SHOT;
			sprintf_s(str1, "MODE : SHOTGUN");
		}
		if (KEYMANAGER->isOnceKeyDown('3')) {
			_player1.mode = MODE_GUIDE;
			sprintf_s(str1, "MODE : GUIDED");
		}
		if (KEYMANAGER->isOnceKeyDown('4')) {
			if (_player1.specialEnable && _player1.specialCount > 0) {
				bulletSpecial(1);
			}
		}
		
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			switch (_player1.mode)
			{
			case MODE_NORMAL :
				bulletFire(11);
				break;
			case MODE_SHOT :
				bulletFire(12);
				break;
			case MODE_GUIDE :
				bulletFire(13);
				break;
			}
		}

		if (KEYMANAGER->isOnceKeyDown('J')) {
			_player2.mode = MODE_NORMAL;
			sprintf_s(str2, "MODE : NORMAL");
		}
		if (KEYMANAGER->isOnceKeyDown('K')) {
			_player2.mode = MODE_SHOT;
			sprintf_s(str2, "MODE : SHOTGUN");
		}
		if (KEYMANAGER->isOnceKeyDown('L')) {
			_player2.mode = MODE_GUIDE;
			sprintf_s(str2, "MODE : GUIDED");
		}
		if (KEYMANAGER->isOnceKeyDown('P')) {
			if (_player2.specialEnable && _player2.specialCount > 0) {
				bulletSpecial(2);
			}
		}


		if (KEYMANAGER->isOnceKeyDown(VK_BACK)) {
			switch (_player2.mode)
			{
			case MODE_NORMAL:
				bulletFire(21);
				break;
			case MODE_SHOT:
				bulletFire(22);
				break;
			case MODE_GUIDE:
				bulletFire(23);
				break;
			}
		}

		//if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _GaugeTop.left += 5;

		for (int i = 0; i < BULLETMAX; i++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_bullet1[i].rc, &_player2.rc))
			{
				_bullet1[i].isFire = false;
				_bullet1[i].rc = RectMakeCenter(_player1.rc.right + 10, _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2, 10, 10);

				_Gauge2Top.left += 20;				
			}
			if (IntersectRect(&temp, &_bullet1[i].rc, &_obstacle[0].rc) || IntersectRect(&temp, &_bullet1[i].rc, &_obstacle[1].rc))
			{
				_bullet1[i].isFire = false;
				_bullet1[i].rc = RectMakeCenter(_player1.rc.right + 10, _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2, 10, 10);
			}
		}

		for (int i = 0; i < BULLETMAX; i++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_bullet2[i].rc, &_player1.rc))
			{
				_bullet2[i].isFire = false;
				_bullet2[i].rc = RectMakeCenter(_player2.rc.left - 10, _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2, 10, 10);

				_Gauge1Top.left += 20;
			}
			if (IntersectRect(&temp, &_bullet2[i].rc, &_obstacle[0].rc) || IntersectRect(&temp, &_bullet2[i].rc, &_obstacle[1].rc))
			{
				_bullet2[i].isFire = false;
				_bullet2[i].rc = RectMakeCenter(_player2.rc.left - 10, _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2, 10, 10);
			}
		}

		if (_Gauge1Top.right - _Gauge1Top.left <= 300)
		{
			_r1 = 250;
			_g1 = 250;
		}
		if (_Gauge1Top.right - _Gauge1Top.left <= 300 && _player1.specialCount > 0) {
			_r3 = 250;
			_player1.specialEnable = true;
		}
		if (_Gauge1Top.right - _Gauge1Top.left <= 100)
		{
			_r1 = 250;
			_g1 = 0;
		}
		if (_Gauge1Top.left >= _Gauge1Top.right) {
			_isGameOver = true;
			sprintf_s(str, "Player2 Win! : Press R to Restart");
			_Gauge1Top.left = _Gauge1Bottom.right;
		}

		if (_Gauge2Top.right - _Gauge2Top.left <= 300)
		{
			_r2 = 250;
			_g2 = 250;
		}

		if (_Gauge2Top.right - _Gauge2Top.left <= 300 && _player2.specialCount > 0) {
			_r4 = 250;
			_player2.specialEnable = true;
		}
		if (_Gauge2Top.right - _Gauge2Top.left <= 100)
		{
			_r2 = 250;
			_g2 = 0;
		}
		if (_Gauge2Top.left >= _Gauge2Top.right) {
			_isGameOver = true;
			sprintf_s(str, "Player1 Win! : Press R to Restart");
			_Gauge2Top.left = _Gauge2Bottom.right;
		}

		bulletMove();
		obstacleMove();
	}


	if (_isGameOver) {
		if (KEYMANAGER->isOnceKeyDown('R'))
		{
			init();
		}
	}
}

//그려주는 함수
void mainGame::render(HDC hdc)	
{
	Rectangle(hdc, _area1.left, _area1.top, _area1.right, _area1.bottom);
	Rectangle(hdc, _area2.left, _area2.top, _area2.right, _area2.bottom);

	Rectangle(hdc, _player1.rc.left, _player1.rc.top, _player1.rc.right, _player1.rc.bottom);
	Rectangle(hdc, _player2.rc.left, _player2.rc.top, _player2.rc.right, _player2.rc.bottom);
	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _obstacle[i].rc.left, _obstacle[i].rc.top, _obstacle[i].rc.right, _obstacle[i].rc.bottom);
	}

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet1[i].isFire) continue;
		Ellipse(hdc, _bullet1[i].rc.left, _bullet1[i].rc.top, _bullet1[i].rc.right, _bullet1[i].rc.bottom);
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet2[i].isFire) continue;
		Ellipse(hdc, _bullet2[i].rc.left, _bullet2[i].rc.top, _bullet2[i].rc.right, _bullet2[i].rc.bottom);
	}

	Rectangle(hdc, _Gauge1Bottom.left, _Gauge1Bottom.top, _Gauge1Bottom.right, _Gauge1Bottom.bottom);
	Rectangle(hdc, _Gauge2Bottom.left, _Gauge2Bottom.top, _Gauge2Bottom.right, _Gauge2Bottom.bottom);
	
	HBRUSH brush1 = CreateSolidBrush(RGB(_r1, _g1, 0));
	Rectangle(hdc, _Gauge1Top.left, _Gauge1Top.top, _Gauge1Top.right, _Gauge1Top.bottom);
	FillRect(hdc, &_Gauge1Top, brush1);	
	DeleteObject(brush1);
	HBRUSH brush2 = CreateSolidBrush(RGB(_r2, _g2, 0));
	Rectangle(hdc, _Gauge2Top.left, _Gauge2Top.top, _Gauge2Top.right, _Gauge2Top.bottom);
	FillRect(hdc, &_Gauge2Top, brush2);
	DeleteObject(brush2);

	SetDCBrushColor(hdc, RGB(_r3, 100, 100));
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	Ellipse(hdc, _SpecialAlarm1.left, _SpecialAlarm1.top, _SpecialAlarm1.right, _SpecialAlarm1.bottom); 

	SetDCBrushColor(hdc, RGB(_r4, 100, 100));
	SelectObject(hdc, GetStockObject(DC_BRUSH));
	Ellipse(hdc, _SpecialAlarm2.left, _SpecialAlarm2.top, _SpecialAlarm2.right, _SpecialAlarm2.bottom);

	TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	TextOut(hdc, _Gauge1Bottom.left, _Gauge1Bottom.bottom, str1, strlen(str1));
	TextOut(hdc, _Gauge2Bottom.right - 130, _Gauge2Bottom.bottom, str2, strlen(str2));
}

//총알을 발사하는 함수
void mainGame::bulletFire(int shootType)
{
	int player = shootType / 10;
	int type = shootType % 10;

	switch (player)
	{
		case 1:
			switch (type) {
			case 1: 
				for (int i = 0; i < BULLETMAX; i++)
				{
					if (_bullet1[i].isFire) continue;
					_bullet1[i].isFire = true;
					_bullet1[i].isGuided = false;
					_bullet1[i].rc = RectMakeCenter(_player1.rc.right + 10, _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2, 10, 10);
					break;
				}
			break;

			case 2:
				for (int i = 0; i < BULLETMAX; i++)
				{
					if (_bullet1[i].isFire) continue;
					for (int j = 0; j < 5; j++) {
						_bullet1[i + j].isFire = true;
						_bullet1[i + j].isGuided = false;
						_bullet1[i + j].rc = RectMakeCenter(_player1.rc.right + 10, (_player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2) - 100 + j * 50, 10, 10);
					}
					break;
				}
			break;

			case 3:
				for (int i = 0; i < BULLETMAX; i++)
				{
					if (_bullet1[i].isFire) continue;
					_bullet1[i].isFire = true;
					_bullet1[i].isGuided = true;
					_bullet1[i].rc = RectMakeCenter(_player1.rc.right + 10, _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2, 10, 10);
					break;
				}
			break;
			}
		break;

		case 2:
			switch (type) {
			case 1:
				for (int i = 0; i < BULLETMAX; i++)
				{
					if (_bullet2[i].isFire) continue;
					_bullet2[i].isFire = true;
					_bullet2[i].isGuided = false;
					_bullet2[i].rc = RectMakeCenter(_player2.rc.left - 10, _player2.rc.top + (_player2.rc.bottom - _player2.rc.top) / 2, 10, 10);
				break;
				}
			break;

			case 2:
				for (int i = 0; i < BULLETMAX; i++)
				{
					if (_bullet2[i].isFire) continue;
					for (int j = 0; j < 5; j++){
						_bullet2[i + j].isFire = true;
						_bullet2[i + j].isGuided = false;
						_bullet2[i + j].rc = RectMakeCenter(_player2.rc.left - 10, (_player2.rc.top + (_player2.rc.bottom - _player2.rc.top) / 2) - 100 + j * 50, 10, 10);
					}
				break;
				}
			break;

			case 3:
				for (int i = 0; i < BULLETMAX; i++)
				{
					if (_bullet2[i].isFire) continue;
					_bullet2[i].isFire = true;
					_bullet2[i].isGuided = true;
					_bullet2[i].rc = RectMakeCenter(_player2.rc.left - 10, _player2.rc.top + (_player2.rc.bottom - _player2.rc.top) / 2, 10, 10);
					break;
				}
			break;
			}

		break;
	}
}

void mainGame::bulletMove(void)
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet1[i].isFire) continue;
		_bullet1[i].rc.left += _bullet1[i].speed;
		_bullet1[i].rc.right += _bullet1[i].speed;
		if (_bullet1[i].isGuided) {
			if (_bullet1[i].rc.bottom < _player2.rc.top + 25) {
				_bullet1[i].rc.top += 3;
				_bullet1[i].rc.bottom += 3;
			}
			else if (_bullet1[i].rc.top > _player2.rc.bottom - 25){
				_bullet1[i].rc.top -= 3;
				_bullet1[i].rc.bottom -= 3;
			}
		}
		if (_bullet1[i].rc.left > WINSIZEX) _bullet1[i].isFire = false;
	}
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet2[i].isFire) continue;
		_bullet2[i].rc.left -= _bullet2[i].speed;
		_bullet2[i].rc.right -= _bullet2[i].speed;

		if (_bullet2[i].isGuided) {
			if (_bullet2[i].rc.bottom < _player1.rc.top + 25) {
				_bullet2[i].rc.top += 3;
				_bullet2[i].rc.bottom += 3;
			}
			else if (_bullet2[i].rc.top > _player1.rc.bottom - 25) {
				_bullet2[i].rc.top -= 3;
				_bullet2[i].rc.bottom -= 3;
			}
		}
		if (_bullet2[i].rc.right < 0) _bullet2[i].isFire = false;
	}
}


void mainGame::obstacleMove(void)
{
	for (int i = 0; i < 2; i++)
	{
		if (_obstacle[i].rc.top < 0) {
			_obstacle[i].moveUp = false;
		}
		if (_obstacle[i].rc.bottom > WINSIZEY) {
			_obstacle[i].moveUp = true;
		}

		if (_obstacle[i].moveUp) {
			_obstacle[i].rc.top -= _obstacle[i].speed;
			_obstacle[i].rc.bottom -= _obstacle[i].speed;
		}
		else {
			_obstacle[i].rc.top += _obstacle[i].speed;
			_obstacle[i].rc.bottom += _obstacle[i].speed;
		}
	}
}


void mainGame::bulletSpecial(int player) {
	switch (player) {
	
	case 1:
		for (int i = 0; i < BULLETMAX; i++)
		{
			if (_bullet1[i].isFire) continue;
			for (int j = 0; j < 25; j++) {
				_bullet1[i + j].isFire = true;
				_bullet1[i + j].isGuided = false;
				_bullet1[i + j].rc = RectMakeCenter(_player1.rc.right + 10 + RND->getFromIntTo(0,10), _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2 - 600 + j * 50, 10, 10);
			}
			_player1.specialCount--;
			_r3 = 100;
			break;
		}		
	break;

	case 2:
		for (int i = 0; i < BULLETMAX; i++)
		{
			if (_bullet2[i].isFire) continue;
			for (int j = 0; j < 25; j++) {
				_bullet2[i + j].isFire = true;
				_bullet2[i + j].isGuided = false;
				_bullet2[i + j].rc = RectMakeCenter(_player2.rc.left - 10 + RND->getFromIntTo(0, 10), _player1.rc.top + (_player1.rc.bottom - _player1.rc.top) / 2 - 600 + j * 50, 10, 10);
			}
			_r4 = 100;
			_player2.specialCount--;
			break;
		}	
	break;
	}
}