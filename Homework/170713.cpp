#include<iostream>
#include<time.h>
#include<windows.h>
#include <stdio.h> 
using namespace std;

/// define
#define BULLETMAX 100
#define FULLSCREEN

/// enum
enum TEST {
	TEST_ONE,
	TEST_TWO,
	TEST_THREE
};

void main(void) {

	// ifdef. define 선언했는가 안했는가에 따라 다른 작업을 수행
#ifdef FULLSCREEN
	cout << "화면을 풀스크린으로 띄우시오" << endl;;
#else
	cout << "화면을 창모드로 띄우시오" << endl;
#endif

	// 래핑. 호환성 때문에 쓰임
	bool result;
	BOOL result;

	// enum 활용
	int num[TEST_THREE];
	num[TEST_ONE] = 5;
	num[TEST_TWO] = 7;

	// define 활용
	srand(time(NULL));

	int bullet[BULLETMAX];

	for (int i = 0; i < BULLETMAX; i++) {
		bullet[i] = i;
	}

	int dest, sour, temp;
	for (int i = 0; i < BULLETMAX; i++) {
		dest = rand() % BULLETMAX;
		sour = rand() % BULLETMAX;

		temp = bullet[dest];
		bullet[dest] = bullet[sour];
		bullet[sour] = temp;
	}

	for (int i = 0; i < BULLETMAX; i++) {
		cout << bullet[i] << endl;

	}

	// 과제, 하이로우 세븐
	// 덱에서 다섯 장을 판단 깐다
	// 배팅 후 선택. 1. 로우, 2. 세븐, 3. 하이
	// 다음 뽑은 한장의 결과에 따라 승패 결정(로우 하이는 2배, 세븐은 13배)
	// 그 후 다섯 장 중 한장을 버리고, 방금 뽑은 한 장을 판에 추가로 깐다
	// 이후 반복

}
