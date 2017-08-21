#pragma once
#include "gameNode.h"

#define PI 3.141592654f

#define BULLETMAX 50

struct tagBullet
{
	float x, y;
	float speed;
	float angle;
	float radius;
	bool isFire;
	float gravity;
	int count;

	float xPrev, yPrev;
};

struct tagCannon
{
	POINT center;		//캐논의 중점
	POINT cannonEnd;	//캐논 포의 끝점
	int radius;			//붼지름
	int cannon;			//포신 길이
	float angle;		//각도
};

class mainGame : public gameNode
{
private:
	tagBullet _bullet[BULLETMAX];
	tagBullet _feed;
	tagCannon _cannon;
	int bulletMax;

public:
	virtual HRESULT init(void);		//초기화
	virtual void release(void);		//메모리 해제
	virtual void update(void);		//연산관련(타이머)
	virtual void render(HDC hdc);	//그려주는 함수
	
	void bulletFire(void);
	void bulletMove(void);

	void bulletCollision(void);

	mainGame();
	~mainGame();
};

