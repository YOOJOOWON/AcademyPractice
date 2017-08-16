#pragma once
#include "gameNode.h"

#define PI 3.141592654f

class mainGame : public gameNode
{
private:
	//���ѷ� == 2 * PI * Radius(������)
	//���� ���� == PI * (Radius * Radius)

	//���� : ȣ�� ���̿� �������� ���̰� ���� ���� 1����
	//1���� : 57.3��
	//PI		== 180��
	//PI / 2	== 90��
	//PI / 4	== 45��
	//PI / 180	== 1�� 

	//�ϴ� API�� �⺻������ ���� ��ġ�� ä���ϰ� �ִ�.

	float _radian;
	float _degree;

	POINT _pos;
	POINT _pos2;
	POINT _pos3;

	RECT _circle1;
	RECT _circle2;
	RECT _rect;

	int _r1, _r2, _r3, _g1, _g2, _g3;

	float _dist1,_dist2;

	int _mes1, _mes2;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ
	virtual void release(void);		//�޸� ����
	virtual void update(void);		//�������(Ÿ�̸�)
	virtual void render(HDC hdc);	//�׷��ִ� �Լ�

	


	mainGame();
	~mainGame();
};

