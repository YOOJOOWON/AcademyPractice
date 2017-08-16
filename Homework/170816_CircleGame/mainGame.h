#pragma once
#include "gameNode.h"

#define PI 3.141592654f

class mainGame : public gameNode
{
private:
	//원둘레 == 2 * PI * Radius(반지름)
	//원의 넓이 == PI * (Radius * Radius)

	//라디안 : 호의 길이와 반지름의 길이가 같을 때를 1라디안
	//1라디안 : 57.3도
	//PI		== 180도
	//PI / 2	== 90도
	//PI / 4	== 45도
	//PI / 180	== 1도 

	//일단 API는 기본적으로 라디안 수치를 채택하고 있다.

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
	virtual HRESULT init(void);		//초기화
	virtual void release(void);		//메모리 해제
	virtual void update(void);		//연산관련(타이머)
	virtual void render(HDC hdc);	//그려주는 함수

	


	mainGame();
	~mainGame();
};

