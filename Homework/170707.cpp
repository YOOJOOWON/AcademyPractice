#include <iostream>
#include <time.h>

using namespace std;
void main(void) {
	//반복문
	//1. for문
	//    초기화      범위   연산
	for (int i = 0; i < 12; i++) {
		cout << "haha" << endl;
	}

	//2중 for문
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << " X " << j << " = " << i * j << endl;
		}
	}

	//2. while문
	//참일 때만 동작한다
	//기본적으로 무한루프를 돈다
	//제어문이 필수적

	/*
	while (true) {
		cout << "꺼내줘!!" << endl;
	}
	*/

	srand(NULL);

	int OrcHP = 50000;
	int OrcAtk = 0;
	int ElfHP = 50000;
	int ElfAtk = 0;

	while (OrcHP >= 0 && ElfHP >= 0) {
		OrcAtk = rand() % 1000;
		ElfAtk = rand() % 1000;
		OrcHP -= ElfAtk;
		ElfHP -= OrcAtk;
		cout << "엘프 공격 : " << ElfAtk << endl;
		cout << "오크 HP : " << OrcHP << endl;
		cout << "오크 반격 : " << OrcAtk << endl;
		cout << "엘프 HP : " << ElfHP << endl;
	}

	//제어문
	//1. break : 연산을 중지하고 빠져나간다
	//2. continue : 연산을 건너뛴다(처음으로 가는 것처럼 보임)
	//3. return : 값을 반환하고 종료
	//4. go to : go to home


	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) continue;
		if (i > 5) break;
		cout << i << endl;
	}

	//1. 컴퓨터틑 0 ~ 999 까지의 수 중에 랜덤하게 하나를 갖는다
	//2. 플레이어는 10번의 기회가 있다.
	//3. 플레이어가 수를 넣으면 컴퓨터는 그 수가 큰지, 작은지, 정답인지 알려준다.
	//4. 물론, 잘못 넣으면 예외처리를 해준다

	srand(NULL);
	int comNum = rand() % 1000;
	int inputNum;
	int roundCount = 10;
	cout << "하하, 내가 무슨 숫자를 생각하고 있는지 10번만에 맞춰보아라." << endl;

	while (true) {
		cout << "입력 : ";
		cin >> inputNum;
		if (inputNum == comNum) {
			cout << "하하, 정답이다." << endl;
			break;
		}
		if (inputNum < comNum && inputNum >= 0) {
			cout << "그 숫자는 내가 생각한 것보다 작다." << endl;
			roundCount--;
		}
		if (inputNum > comNum && inputNum < 1000) {
			cout << "그 숫자는 내가 생각한 것보다 크다." << endl;
			roundCount--;
		}
		if (inputNum < 0 || inputNum >= 1000) {
			cout << "그 숫자는 정해진 범위의 숫자가 아니다" << endl;
			continue;
		}
		cout << roundCount << "회 남았다" << endl;
		if (roundCount <= 0) {
			cout << "틀렸다 요놈아!" << endl;
			break;
		}

	}

	// Homework
	// 0 ~ 9 중에 서로 다른 숫자 3개
	// 1. 숫자만 일치하면 Ball
	// 2. 위치까지 일치하면 Strike
	// 3. 전혀 일치하지 않으면 Out
}