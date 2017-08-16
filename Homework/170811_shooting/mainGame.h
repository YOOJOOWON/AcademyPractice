#pragma once
#include "gameNode.h"

enum SHOOTMODE {
	MODE_NORMAL,
	MODE_SHOT,
	MODE_GUIDE
};

struct tagBullet
{
	RECT rc;
	float speed;
	bool isFire;
	bool isGuided;
};

struct tagPlayer 
{
	RECT rc;
	SHOOTMODE mode;
	bool specialEnable;
	int specialCount;
};


struct tagObstacle {
	RECT rc;
	float speed;
	bool moveUp;
};
#define BULLETMAX 100

class mainGame : public gameNode
{
private:
	tagBullet _bullet1[BULLETMAX];
	tagBullet _bullet2[BULLETMAX];

	tagPlayer  _player1;
	tagPlayer  _player2;

	tagObstacle _obstacle[2];

	RECT _area1;
	RECT _area2;

	RECT _Gauge1Bottom;
	RECT _Gauge1Top;
	RECT _Gauge2Bottom;
	RECT _Gauge2Top;


	RECT _SpecialAlarm1;
	RECT _SpecialAlarm2;

	int _r1, _g1;
	int _r2, _g2;
	int _r3, _r4;

	char str[64];
	float countdown;

	char str1[64];
	char str2[64];
	
	bool _isStart;
	bool _isGameOver;


public:
	virtual HRESULT init(void);	//�ʱ�ȭ
	virtual void release(void);	//�޸� ����
	virtual void update(void);	//�������(Ÿ�̸�)
	virtual void render(HDC hdc);	//�׷��ִ� �Լ�

	void bulletFire(int shootType);

	void bulletMove(void);

	void bulletSpecial(int player);

	void obstacleMove(void);


	mainGame();
	~mainGame();
};

