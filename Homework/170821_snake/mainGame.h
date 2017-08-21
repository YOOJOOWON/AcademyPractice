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
	POINT center;		//ĳ���� ����
	POINT cannonEnd;	//ĳ�� ���� ����
	int radius;			//������
	int cannon;			//���� ����
	float angle;		//����
};

class mainGame : public gameNode
{
private:
	tagBullet _bullet[BULLETMAX];
	tagBullet _feed;
	tagCannon _cannon;
	int bulletMax;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ
	virtual void release(void);		//�޸� ����
	virtual void update(void);		//�������(Ÿ�̸�)
	virtual void render(HDC hdc);	//�׷��ִ� �Լ�
	
	void bulletFire(void);
	void bulletMove(void);

	void bulletCollision(void);

	mainGame();
	~mainGame();
};

