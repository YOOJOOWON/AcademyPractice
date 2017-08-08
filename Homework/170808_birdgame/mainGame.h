#pragma once
#include "gameNode.h"

struct tagWall
{
	RECT top;
	RECT bot;
	bool isScored;
};


class mainGame : public gameNode
{
private:
	RECT _rc;
	
	RECT _land[3];

	tagWall _wall[10];

	char str[64];
	char str2[64];
	float countdown;

	int _x, _y;
	float _jumpPower, _gravity;

	bool _isStart;
	bool _isGameOver;
	bool _isJump;

	int score;
	float level;

public:
	virtual HRESULT init(void);	//�ʱ�ȭ
	virtual void release(void);	//�޸� ����
	virtual void update(void);	//�������(Ÿ�̸�)
	virtual void render(HDC hdc);	//�׷��ִ� �Լ�


	mainGame();
	~mainGame();
};

