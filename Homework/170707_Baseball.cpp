#include<iostream>
#include<time.h>

using namespace std;

void main(void) {

	srand(time(NULL));
	int c1, c2, c3;
	int input;
	int p1, p2, p3;
	int countChance = 20;
	int countBall, countStrike;

	//첫 자리가 0이 아니고, 서로 중복되지 않는 숫자를 생성
	c1 = rand() % 10;
	while (c1 == 0) { c1 = rand() % 10; }
	c2 = rand() % 10;
	while (c2 == c1) { c2 = rand() % 10;}
	c3 = rand() % 10;
	while (c3 == c1 || c3 == c2) { c3 = rand() % 10; }
	

	cout << "신나고 재미있는 베이스볼 게임~" << endl;
	cout << "서로 다른 세 자리 숫자를 입력하여 스무 번만에 맞추는 게임입니다." << endl;
	cout << "자리는 다르지만 숫자가 같을 경우 볼(B)." << endl;
	cout << "자리도 같고 숫자도 같을 경우 스트라이크(S)." << endl;
	cout << "자리와 숫자 둘 다 다를 경우에는 아웃(Out) 입니다." << endl;
	
	while (countChance > 0)
	{
		countBall = 0;
		countStrike = 0;
		cout << "숫자를 입력하세요 (남은 회수 " << countChance << "번) : ";

		cin >> input;
		p1 = input / 100;
		p2 = input % 100 / 10;
		p3 = input % 10;

		// 잘못 입력한 경우의 예외처리
		if (input < 100 || input >= 1000) {
			cout << "해당 범위를 벗어난 숫자입니다. 다시 입력해주세요." << endl;
			continue;
		}
		if (p1 == 0) {
			cout << "첫 자리에는 0이 들어갈 수 없습니다. 다시 입력해주세요." << endl;
			continue;
		}
		if (p1 == p2 || p2 == p3 || p3 == p1) {
			cout << "각 자리가 서로 다른 숫자가 아닙니다. 다시 입력해주세요." << endl;
			continue;
		}

		// 각 숫자의 스트라이크, 볼 판정
		if (p1 == c1) { countStrike++; }
		if (p2 == c2) { countStrike++; }
		if (p3 == c3) { countStrike++; }
		if (p1 == c2) { countBall++; }
		if (p1 == c3) { countBall++; }
		if (p2 == c1) { countBall++; }
		if (p2 == c3) { countBall++; }
		if (p3 == c1) { countBall++; }
		if (p3 == c2) { countBall++; }
		
		// 3스트라이크면 정답. break로 루프문 빠져나옴.
		if (countStrike == 3) {
			cout << "정답입니다! 답은 " << input << "입니다." << endl;
			break;
		}
		// 그 외의 경우 오답처리. Ball, Strike, Out을 알려주고 남은 회수 1 줄인다.
		else {
			cout << "오답입니다. ";
			if (countBall > 0)
				cout << countBall << "B";
			if (countStrike > 0)
				cout << countStrike << "S";
			if (countBall == 0 && countStrike == 0)
				cout << "Out";
			cout << endl;
			countChance--;
		}

		if (countChance == 0)
			cout << "기회를 모두 소진하셨습니다. 잘 가세요 뿌뿌." << endl;
	}


}
