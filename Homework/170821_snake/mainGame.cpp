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

	_cannon.angle = PI / 2;
	_cannon.cannon = 100;
	_cannon.radius = 100;
	_cannon.center.x = WINSIZEX / 2;
	_cannon.center.y = WINSIZEY;

	memset(_bullet, 0, sizeof(_bullet));

	for (int i = 0; i < BULLETMAX; i++)
	{
		_bullet[i].speed = 5.0f;
		_bullet[i].radius = 30;
		_bullet[i].isFire = false;
		_bullet[i].count = 0;
	}

	_feed.x = (float) RND->getFromIntTo(30, WINSIZEX - 30);
	_feed.y = (float)RND->getFromIntTo(30, WINSIZEY - 30);
	_feed.radius = 30;

	bulletMax = 5; bulletFire();
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

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		if (_bullet[0].angle > 0.1 || _bullet[0].angle < 2 * PI - 0.1) {
			if (_bullet[0].angle < PI)
				_bullet[0].angle -= 0.1f;
			else _bullet[0].angle += 0.1f;
		}
		else _bullet[0].angle = 0.001f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		if (_bullet[0].angle < PI - 0.1 || _bullet[0].angle > PI + 0.1) {
			if (_bullet[0].angle < PI)
				_bullet[0].angle += 0.1f;
			else _bullet[0].angle -= 0.1f;
		}
		else _bullet[0].angle = PI;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) {
		if (_bullet[0].angle < PI / 2 - 0.1 || _bullet[0].angle > PI / 2 + 0.1) {
			if (_bullet[0].angle >= PI / 2 && _bullet[0].angle <= PI * 3 / 2)
				_bullet[0].angle -= 0.1f;
			else if (_bullet[0].angle <= PI / 2 || _bullet[0].angle >= PI * 3 / 2)
				_bullet[0].angle += 0.1f;
		}
		else _bullet[0].angle = PI / 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
		if (_bullet[0].angle < PI / 2 - 0.1 || _bullet[0].angle > PI / 2 + 0.1) {
			if (_bullet[0].angle >= PI / 2 && _bullet[0].angle <= PI * 3 / 2)
				_bullet[0].angle += 0.1f;
			else if (_bullet[0].angle <= PI / 2 || _bullet[0].angle >= PI * 3 / 2)
				_bullet[0].angle -= 0.1f;
		}
		else _bullet[0].angle = PI * 3 / 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE)) 


	_cannon.cannonEnd.x = cosf(_cannon.angle) * _cannon.cannon + _cannon.center.x;
	_cannon.cannonEnd.y = -sinf(_cannon.angle) * _cannon.cannon + _cannon.center.y;

	if (_bullet[0].angle < 0)
		_bullet[0].angle = 2 * PI + _bullet[0].angle;
	if (_bullet[0].angle > 2 * PI)
		_bullet[0].angle = _bullet[0].angle - 2 * PI;
	
	bulletMove();
	bulletCollision();
}

//그려주는 함수
void mainGame::render(HDC hdc)	
{

	char strRadian[128];
	char strPos[128];
	char strPrev[128];
	char strLength[128];
	sprintf_s(strRadian, "angle %.2f",
		_bullet[0].angle);
	TextOut(hdc, 100, 100, strRadian, strlen(strRadian));
	sprintf_s(strPos, "xPos %.2f yPos %.2f",
		_bullet[0].x, _bullet[0].y);
	TextOut(hdc, 100, 150, strPos, strlen(strPos));
	sprintf_s(strPrev, "xPrev %.2f yPrev %.2f",
		_bullet[0].xPrev, _bullet[0].yPrev);
	TextOut(hdc, 100, 200, strPrev, strlen(strPrev));
	sprintf_s(strLength, "지렁이 길이 : %d",
		bulletMax + 1);
	TextOut(hdc, 100, 250, strLength, strlen(strLength));
	

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;

		EllipseMakeCenter(hdc, _bullet[i].x, _bullet[i].y,
			_bullet[i].radius * 2, _bullet[i].radius * 2);
	}
	EllipseMakeCenter(hdc, _feed.x, _feed.y,
		_feed.radius * 2, _feed.radius * 2);


}

void mainGame::bulletFire(void)
{
	for (int i = 0; i <= bulletMax; i++)
	{
		_bullet[i].isFire = true;
		_bullet[i].x = cosf(_cannon.angle) * (_cannon.cannon + 5) + _cannon.center.x;
		_bullet[i].y = -sinf(_cannon.angle) * (_cannon.cannon + 5) + _cannon.center.y - 660 + i * 40;
		_bullet[i].xPrev = _bullet[i].x;
		_bullet[i].yPrev = _bullet[i].y;
		_bullet[i].angle = _cannon.angle;
	}
}

void mainGame::bulletMove(void)
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (!_bullet[i].isFire) continue;
	
		if (_bullet[i].count == 0) {
			_bullet[i].xPrev = _bullet[i].x;
			_bullet[i].yPrev = _bullet[i].y; 
			_bullet[i].count = 10;
		}
		_bullet[i].count--;

		if (i == 0) {
			_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
			_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed;
		}

		else {
			if (getDistance(_bullet[i].x, _bullet[i].y, _bullet[i - 1].xPrev, _bullet[i - 1].yPrev) > 0.01f) {
				_bullet[i].angle = getAngle(_bullet[i].x, _bullet[i].y, _bullet[i - 1].xPrev, _bullet[i - 1].yPrev);

				_bullet[i].x += cosf(_bullet[i].angle) * _bullet[i].speed;
				_bullet[i].y += -sinf(_bullet[i].angle) * _bullet[i].speed;
			}
		}
		//왼쪽
		if (_bullet[i].x - _bullet[i].radius < 0)
		{
			_bullet[i].angle = PI - _bullet[i].angle;
		}

		//오른쪽
		if (_bullet[i].x + _bullet[i].radius > WINSIZEX)
		{
			_bullet[i].angle = PI - _bullet[i].angle;
		}
		//위
		if (_bullet[i].y - _bullet[i].radius < 0)
		{
			_bullet[i].angle = 2 * PI - _bullet[i].angle;
		}
		//아래
		if (_bullet[i].y + _bullet[i].radius > WINSIZEY)
		{
			_bullet[i].angle = 2 * PI - _bullet[i].angle;
		}
	}
}

void mainGame::bulletCollision(void)
{
	if (_bullet[0].isFire && bulletMax < BULLETMAX) {
		if (_bullet[0].radius * 2 > getDistance(_bullet[0].x, _bullet[0].y, _feed.x, _feed.y))
		{
			bulletMax++;
			_bullet[bulletMax].isFire = true;
			_bullet[bulletMax].speed = 5.0f;
			_bullet[bulletMax].radius = 30;
			_bullet[bulletMax].count = 0;
			_bullet[bulletMax].x = _bullet[bulletMax-1].x - cosf(_bullet[bulletMax - 1].angle) * 40;
			_bullet[bulletMax].y = _bullet[bulletMax - 1].y + sinf(_bullet[bulletMax - 1].angle) * 40;

			_feed.x = (float)RND->getFromIntTo(30, WINSIZEX - 30);
			_feed.y = (float)RND->getFromIntTo(30, WINSIZEY - 30);
		}
	}
	//for (int i = 0; i < BULLETMAX; i++)
	//{
	//	for (int j = i + 1; j < BULLETMAX; j++)
	//	{
	//		 continue;
	//
	//		_bullet[i].angle = getAngle(_bullet[j].x, _bullet[j].y, _bullet[i].x, _bullet[i].y);
	//		_bullet[j].angle = getAngle(_bullet[i].x, _bullet[i].y, _bullet[j].x, _bullet[j].y);
	//
	//	}
	//}
}