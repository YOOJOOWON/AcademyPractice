#include<iostream>
#include<time.h>

using namespace std;

void main(void) {

	//배열
	//같은 크기의 변수들이 나열되어 있다

	/*
	int number[3];

	number[0] = 3;
	number[1] = 2;
	number[2] = 1;

	int num[4] = { 1,2,3,4 };
	int num1[] = { 1,2,3 };

	for (int i = 0; i < 4; i++) {
		num[i] = i * i;
	}
	for (int i = 0; i < 4; i++) {
		cout << num[i] << endl;
	}
	
	int num2[3][3];
	*/


	//int a = 3;
	//int b = 5;
	//int temp;
	//
	//temp = a;
	//a = b;
	//b = temp;
	//
	//cout << a << b << endl;

	srand(time(NULL));
	int num[10];
	int dest, sour, temp;

	for (int i = 0; i < 10; i++) {
		num[i] = i + 1;
	}

	for (int i = 0; i < 333; i++)
	{
		dest = rand() % 10;
		sour = rand() % 10;

		temp = num[dest];
		num[dest] = num[sour];
		num[sour] = temp;
	}

	for (int i = 0; i < 10; i++) {
		cout << num[i] << endl;
	}

	float speed = 3.5;

	cout << "3턴간 이동한 좌표크기 : " << speed * 3 << endl;

	int distance = speed * 3;

	cout << "이동거리 : " << distance << endl;

	//c++ 형변환
	//static_cast : 일반적인 c스타일 형변환과 같다
	//reinterpret_cast : 비트단위로 형변환 해줌
	//const_cast : const(상수) 속성을 풀어줌
	//dynamic_cast : 엄청 안정적으로 형변환을 해주나 너무 느림
}