#include "stdafx.h"
#include "mainGame.h"
#include <math.h>

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

	_radian = PI;

	_degree = 90;

	_pos.x = 100;
	_pos.y = 100;
	
	_pos2.x = 400;
	_pos2.y = 400;

	_pos3.x = 800;
	_pos3.y = 400;

	_circle1 = RectMakeCenter(_pos.x, _pos.y, 100, 100);
	_circle2 = RectMakeCenter(_pos2.x, _pos2.y, 100, 100);
	_rect = RectMakeCenter(_pos3.x, _pos3.y, 100, 100);

	_r1 = 255;
	_g1 = 255;
	_r2 = 240;
	_g2 = 0;
	_r3 = 0;
	_g3 = 240;

	_dist1 = 0;
	_dist2 = 0;

	_mes1 = 0;
	_mes2 = 0;


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


	_circle1 = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);
	
	_dist1 = ((_ptMouse.x - _pos3.x) * (_ptMouse.x - _pos3.x)) +
		((_ptMouse.y - _pos3.y) * (_ptMouse.y - _pos3.y));
	_dist2 = ((_ptMouse.x - _pos2.x) * (_ptMouse.x - _pos2.x)) +
		((_ptMouse.y - _pos2.y) * (_ptMouse.y - _pos2.y));

	if (_dist2 <= 10000 && _mes1 == 0) {
		_mes1 = 1;
		int _rTemp, _gTemp;
		_rTemp = _r1;
		_gTemp = _g1;
		_r1 = _r2;
		_g1 = _g2;
		_r2 = _rTemp;
		_g2 = _gTemp;
	}
	else if (_dist2 > 10000)
		_mes1 = 0;

	RECT temp;
	if ((_ptMouse.y >= _rect.top && _ptMouse.y <= _rect.bottom)
		|| (_ptMouse.x <= _rect.right && _ptMouse.x >= _rect.left))
	{
		if (IntersectRect(&temp, &_circle1, &_rect))
		{
			if (_mes2 == 0) {
				_mes2 = 1;
				int _rTemp, _gTemp;
				_rTemp = _r1;
				_gTemp = _g1;
				_r1 = _r3;
				_g1 = _g3;
				_r3 = _rTemp;
				_g3 = _gTemp;
			}
		}
		else _mes2 = 0;
	}
	else {
		if (_dist1 < (50 + 50 * sqrt(2.0)) * (50 + 50 * sqrt(2.0)))
		{
			if (_mes2 == 0) {
				_mes2 = 1;
				int _rTemp, _gTemp;
				_rTemp = _r1;
				_gTemp = _g1;
				_r1 = _r3;
				_g1 = _g3;
				_r3 = _rTemp;
				_g3 = _gTemp;
				
			}
		}
		else
			_mes2 = 0;
	}
	
	float radian;
	
}

//그려주는 함수
void mainGame::render(HDC hdc)	
{
	char strRadian[128];
	char strDegree[128];
	char strCheck[128];

	sprintf_s(strRadian, "%ld x %ld y",
		_ptMouse.x, _ptMouse.y);

	TextOut(hdc, 100, 100, strRadian, strlen(strRadian));

	sprintf_s(strDegree, "원과의 거리는 %.2f",
		_dist1);
	TextOut(hdc, 100, 200, strDegree, strlen(strDegree));
	sprintf_s(strCheck, "사각형과의 거리는 %.2f",
		_dist2);
	TextOut(hdc, 100, 300, strCheck, strlen(strCheck));
	
	HBRUSH oldBrush;

	HBRUSH brush1 = CreateSolidBrush(RGB(_r2, _g2, 255));
	oldBrush = (HBRUSH)SelectObject(hdc, brush1);
	Ellipse(hdc, _circle2.left, _circle2.top, _circle2.right, _circle2.bottom);
	SelectObject(hdc, oldBrush);
	DeleteObject(brush1);
	HBRUSH brush2 = CreateSolidBrush(RGB(_r3, _g3, 255));
	oldBrush = (HBRUSH) SelectObject(hdc, brush2);
	Rectangle(hdc, _rect.left, _rect.top, _rect.right, _rect.bottom);	
	SelectObject(hdc, oldBrush);
	DeleteObject(brush2);

	HBRUSH brush3 = CreateSolidBrush(RGB(_r1, _g1, 255));
	oldBrush = (HBRUSH)SelectObject(hdc, brush3);
	Ellipse(hdc, _circle1.left, _circle1.top, _circle1.right, _circle1.bottom);
	SelectObject(hdc, oldBrush);
	DeleteObject(brush3);
}
