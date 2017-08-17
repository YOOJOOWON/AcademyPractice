#pragma once
#include "gameNode.h"

#define PI 3.141592654f
#define GRAVITY 9.8f
#define DOTNUM 100

struct tagBullet
{
	RECT rc;
	float speed;
	float angle;
	float time;

	float x0, y0;
};


class mainGame : public gameNode
{
private:
	RECT _rc;

	tagBullet _bullet;
	bool _isFire;

	float _x0, _y0;
	float _x1, _y1;
	float _x2, _y2;

	float _x22[DOTNUM], _y22[DOTNUM];

	float _angle;
	float _speed;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ
	virtual void release(void);		//�޸� ����
	virtual void update(void);		//�������(Ÿ�̸�)
	virtual void render(HDC hdc);	//�׷��ִ� �Լ�
	
	void bulletFire(void);
	void bulletMove(void);
	void drawBulletLine(void);

	mainGame();
	~mainGame();
};

