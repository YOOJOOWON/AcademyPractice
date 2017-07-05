#include <iostream>
#include <time.h>

using namespace std;

void main(void) {
	//산술 연산자

	// +		더하기
	// -		빼기
	// *		곱하기
	// /		나누기
	// %		나머지

	cout << 8 % 5 << endl;

	srand(time(NULL));

	int num1 = rand() % 6 + 1;
	int num2 = rand();

	cout << "num1의 값은 : " << num1 << endl;
	cout << "num2의 값은 : " << num2 << endl;
	cout << endl;


	int rullet = rand() % 37;
	cout << "구슬을 던집니다." << endl;
	cout << "또로로로로로로로로로~" << endl;
	cout << "나온 룰렛 숫자는 : " << rullet << "입니다" << endl;
	cout << endl;

	//관계 연산자

	// a > b	a는 b보다 크다
	// a < b	a는 b보다 작다
	// a >= b	a는 b보다 크거나 같다
	// a <= b	a는 b보다 작거나 같다
	// a == b	a는 b와 같다
	// a != b	a는 b와 같지 않다

	//논리 연산자

	// a && b	a AND b		a도 참이고, b도 참이다
	// a || b	a OR b		a와 b 둘 중 하나가 참
	// !a		NOT a		a가 아닐때

	//예시

	int playerHP = 200;
	int playerAtk = rand() % 50;
	int enemyHP = 200;
	int enemyAtk = rand() % 50;

	enemyHP -= playerAtk;
	playerHP -= enemyAtk;

	cout << "플레이어의 공격! " << playerAtk << "만큼의 데미지를 입혔다. 적의 현재 체력 " << enemyHP << endl;
	cout << "적의 공격! " << enemyAtk << "만큼의 데미지를 입었다. 플레이어의 현재 체력 " << playerHP << endl;
	cout << endl;

	cout << "출력은 cout" << endl;
	cout << "입력은 cin" << endl;
	cout << "숫자를 입력하시오 : ";

	int num;
	cin >> num;

	cout << "니가 방금 입력한 그것 : " << num << endl;

}	