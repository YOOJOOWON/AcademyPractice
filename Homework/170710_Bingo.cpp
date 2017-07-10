#include<iostream>
#include<time.h>

using namespace std;

void main(void) {

	srand(time(NULL));
	int bingo[5][5];
	int bingoCount = 0;
	int bingoCheck = 0;

	int input;

	int dest, sour, temp;

	//1~25 입력
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			bingo[i][j] = (i * 5) + (j + 1);

	//셔플
	for (int i = 0; i < 50; i++) {
		dest = rand() % 25;
		sour = rand() % 25;
		temp = bingo[dest / 5][dest % 5];
		bingo[dest / 5][dest % 5] = bingo[sour / 5][sour % 5];
		bingo[sour / 5][sour % 5] = temp;
	}

	

	while (true) {
		//화면 출력
		cout << "즐겁고 신나는 빙고 게임~" << endl;
		cout << "각 숫자를 입력하여 #으로 체크합니다." << endl;
		cout << "가로, 세로, 대각선 줄이 #으로 가득하면 빙고!" << endl;
		cout << "3빙고가 완성되면 게임을 종료합니다." << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				cout.width(3);
				if (bingo[i][j] == -1)
					cout << "  # ";
				else
					cout << bingo[i][j] << " ";
			}
			cout << endl;
		}

		//승리조건
		if (bingoCount > 4)
		{
			cout << "축하합니다! 5빙고 완성!" << endl;
			break;
		}

		cout << "현재 빙고 : " << bingoCount << endl;
		cout << "숫자를 입력하세요 : ";


		//숫자 외의 입력 차단
		while (!(cin >> input)) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요 : ";
		}
		//지정된 범위를 벗어난 입력 차단
		if (input < 1 || input > 25) {
			cout << "해당 범위를 벗어난 숫자입니다. 다시 입력해주세요." << endl;
			system("cls");
			continue;
		}

		//입력한 숫자를 #(0)으로 체크
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				if (bingo[i][j] == input)
					bingo[i][j] = -1;
			}
			cout << endl;
		}

		//빙고 확인
		//가로
		bingoCount = 0;
		for (int i = 0; i < 5; i++) {
			bingoCheck = 0;
			for (int j = 0; j < 5; j++) {
				if (bingo[i][j] == -1)
				{
					bingoCheck++;
				}
				if (bingoCheck > 4)
					bingoCount++;
			}
		}
		//세로
		for (int i = 0; i < 5; i++) {
			bingoCheck = 0;
			for (int j = 0; j < 5; j++) {
				if (bingo[j][i] == -1)
				{
					bingoCheck++;
				}
				if (bingoCheck > 4)
					bingoCount++;
			}
		}
		//대각선
		bingoCheck = 0;
		for (int i = 0; i < 5; i++)
		{
			if (bingo[i][i] == -1)
			{
				bingoCheck++;
				cout << bingoCheck << endl;
			}
			if (bingoCheck > 4)
				bingoCount++;
		}
		bingoCheck = 0;
		for (int i = 0; i < 5; i++)
		{
			if (bingo[4-i][i] == -1)
			{
				bingoCheck++;
				if (bingoCheck > 4)
					bingoCount++;
			}
		}
		bingoCheck = 0;

		system("cls");
	}


}
