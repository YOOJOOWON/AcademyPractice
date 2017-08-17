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

	_x0 = WINSIZEX / 2;
	_y0 = WINSIZEY;


	_x1 = WINSIZEX / 2;
	_y1 = WINSIZEY - 100;

	_rc = RectMakeCenter(_x0, _y0, 100, 100);
	
	
	_angle = PI / 2;
	_speed = 50;
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

	

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _angle <= PI) {
		_angle += 0.04f;
		_x1 = _x0 + cosf(_angle) * 100;
		_y1 = _y0 + -sinf(_angle) * 100;
		if (_angle > PI){
			_angle = PI;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _angle >= 0) {
		_angle -= 0.04f;
		_x1 = _x0 + cosf(_angle) * 100;
		_y1 = _y0 + -sinf(_angle) * 100;		
		if (_angle < 0) {
			_angle = 0;
		}
	}
	if (!_isFire && KEYMANAGER->isStayKeyDown(VK_SPACE)) {
		_speed *= 1.01f;
	}

	if (!_isFire && KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
		bulletFire();
	}

	bulletMove();
	if (!_isFire) {
		drawBulletLine();
	}
}

//그려주는 함수
void mainGame::render(HDC hdc)	
{
	char strRadian[128];
	char strPower[128];

	sprintf_s(strRadian, "%.2f x %.2f y angle %.2f",
		_x1, _y1, _angle);

	TextOut(hdc, 100, 100, strRadian, strlen(strRadian));

	sprintf_s(strPower, "Power : %.2f",	_speed);
	TextOut(hdc, 100, 200, strPower, strlen(strPower));

	if (_isFire) {
		Ellipse(hdc, _bullet.rc.left, _bullet.rc.top, _bullet.rc.right, _bullet.rc.bottom);
	}
	else {
		MoveToEx(hdc, _x22[0], _y22[0], NULL);
		for (int i = 1; i < DOTNUM; i++) {
			LineTo(hdc, _x22[i], _y22[i]);
			if (_x22[i] > WINSIZEX || _x22[i] < 0 || _y22[i] > WINSIZEY || _y22[i] < 0)
				break;
		}
	}
	

	Ellipse(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	MoveToEx(hdc, _x0, _y0, NULL);
	LineTo(hdc, _x1, _y1);
}

void mainGame::bulletFire(void) {
	
	_isFire = true;
	_x2 = _x1;
	_y2 = _y1;
	_bullet.rc = RectMakeCenter(_x2, _y2, 10, 10);
	_bullet.angle = _angle;
	_bullet.speed = _speed;
	_bullet.time = 0;
	_bullet.x0 = _x1;
	_bullet.y0 = _y1;

	_speed = 50.0f;
}

void mainGame::bulletMove(void) {
	if (!_isFire) 
		return;

	_bullet.time += 0.1f;

	_x2 = _bullet.x0 + (_bullet.speed * cos(_bullet.angle) * _bullet.time);
	_y2 = _bullet.y0 - (_bullet.speed * sin(_bullet.angle) * _bullet.time) + GRAVITY * _bullet.time * _bullet.time / 2;

	_bullet.rc = RectMakeCenter(_x2, _y2, 10, 10);
	

	if (_bullet.rc.left > WINSIZEX || _bullet.rc.right < 0 || _bullet.rc.top > WINSIZEY || _bullet.rc.bottom < 0)
		_isFire = false;
}

void mainGame::drawBulletLine(void) {
	for (int i = 0; i < DOTNUM; i++) {
		float _time = i * 0.3f;
		_x22[i] = _x1 + (_speed * cos(_angle) * _time);
		_y22[i] = _y1 - (_speed * sin(_angle) * _time) + GRAVITY * _time * _time / 2;


	}


}