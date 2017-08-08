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

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_rc = RectMakeCenter(_x, _y, 50, 50);

	for (int i = 0; i < 10; i++)
	{
		int ran = RND->getFromIntTo(-100, 100);
		_wall[i].top = RectMakeCenter(1000 + i * 450, 0 + ran, 100, 500);
		_wall[i].bot = RectMakeCenter(1000 + i * 450, WINSIZEY - 100 + ran, 100, 500);
		_wall[i].isScored = false;
	}
	for (int i = 0; i < 3; i++)
	{
		_land[i] = RectMakeCenter(i * 300, WINSIZEY - 100, 1000, 100);
	}

	score = 0;
	level = 1.0;

	countdown = 3.0;
	sprintf_s(str, "countdown : %d", static_cast<int>(countdown));
	sprintf_s(str2, "score : %d", score);

	_jumpPower = _gravity = 0.2;
	_isJump = false;
	_isStart = false;
	_isGameOver = false;

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
		if (countdown > 0) {
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
		_y -= _jumpPower;
		_jumpPower -= _gravity;

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_jumpPower = 5;
			_gravity = 0.2;
		}


		for (int i = 0; i < 3; i++)
		{
			_land[i].left -= 5 * level;
			_land[i].right -= 5 * level;

			if (_land[0].right < 0)
			{
				_land[0] = RectMakeCenter(_land[2].right + 300, WINSIZEY - 100, 1000, 100);
			}
			if (_land[1].right < 0)
			{
				_land[1] = RectMakeCenter(_land[0].right + 300, WINSIZEY - 100, 1000, 100);
			}
			if (_land[2].right < 0)
			{
				_land[2] = RectMakeCenter(_land[1].right + 300, WINSIZEY - 100, 1000, 100);
			}

			if (_rc.bottom > _land[i].top)
			{
				_isJump = false;
				_y = _land[i].top - ((_rc.bottom - _rc.top) / 2);

			}
		}

		for (int i = 0; i < 10; i++) {
			_wall[i].top.left -= 5 * level;
			_wall[i].top.right -= 5 * level;
			_wall[i].bot.left -= 5 * level;
			_wall[i].bot.right -= 5 * level;
			
			if (((_rc.bottom > _wall[i].bot.top && _rc.right > _wall[i].bot.left && _rc.left < _wall[i].bot.right))
				|| ((_rc.top < _wall[i].top.bottom && _rc.right > _wall[i].top.left && _rc.left < _wall[i].top.right)))
			{
				_isGameOver = true;
				sprintf_s(str, "Game Over : Press Space to Restart");
			}
			if (_wall[i].top.right < 0) {
				int back = (i == 0) ? 9 : i - 1;
				int ran = RND->getFromIntTo(-100, 100);
				_wall[i].top = RectMakeCenter(_wall[back].top.right + 450, 0 + ran, 100, 500);
				_wall[i].bot = RectMakeCenter(_wall[back].bot.right + 450, WINSIZEY - 100 + ran, 100, 500);
				_wall[i].isScored = false;
			}

			if (_wall[i].top.right < WINSIZEX / 2 - 100 && !(_wall[i].isScored)) {
				score++;
				_wall[i].isScored = true;
			}
		}
	}

	if (score / 10 >= level) {
		level += 0.2;
	}



	if (_isGameOver) {
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			init();
		}
	}


	_rc = RectMakeCenter(_x, _y, 50, 50);
	sprintf_s(str2, "score : %d", score);
}

//그려주는 함수
void mainGame::render(HDC hdc)	
{
	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);


	for (int i = 0; i < 10; i++)
	{
		Rectangle(hdc, _wall[i].top.left, _wall[i].top.top, _wall[i].top.right, _wall[i].top.bottom);
		Rectangle(hdc, _wall[i].bot.left, _wall[i].bot.top, _wall[i].bot.right, _wall[i].bot.bottom);
	}
	for (int i = 0; i < 3; i++)
	{
		Rectangle(hdc, _land[i].left, _land[i].top, _land[i].right, _land[i].bottom);
	}
	TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	TextOut(hdc, 100, 100, str2, strlen(str2));
	
}