#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;


void main(void) {

	//과제
	//1. strtok -> 띄어쓰기마다 나눠서 출력
	
	//char str[] = "Harry Potter and the half-blood prince";
	//char *ptr;
	//
	//ptr = strtok(str, " ");
	//
	//while (ptr != NULL)
	//{
	//	printf("%s\n", ptr);
	//	ptr = strtok(NULL, " ");
	//}

	//2. 포커카드
	//	카드 2장 드로우. 그 후 배팅
	//	소지금 : 100만원
	//	배팅(최소금액 10000)
	//  두 카드 사이의 숫자가 나오면 승리. 배팅액의 2배 지급. 아니면 패배.

	srand(time(NULL));

	int card[52];
	int haveMoney = 1000000;
	int betMoney = 0;
	int cardCount = 0;

	int input = 0;

	//카드를 덱에 넣는다
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
		cardCount++;
	}

	//덱 셔플
	int dest, sour, temp;
	for (int i = 0; i < 300; i++) 
	{
		dest = rand() % 52;
		sour = rand() % 52;
		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}

	int firstCard;
	int secondCard;
	int myCard;

	while (true) {
		cout << "신나고 재미있는 카드게임" << endl;
		cout << "두 장의 카드를 앞면으로 꺼냅니다." << endl;
		cout << "그 다음 배팅을 할 지 말 지 정합니다.(최소배팅액 10000원)" << endl;
		cout << "배팅을 할 경우 덱에서 한 장을 더 꺼냅니다. " << endl;
		cout << "그 카드의 숫자가 두 카드의 숫자 사이에 이길 경우 승리, 배팅액의 2배를 받습니다." << endl;
		cout << "두 카드의 숫자 사이의 범위에서 벗어날 경우 패배, 배팅액을 잃습니다." << endl;
		cout << "승부를 포기할 경우, 최소배팅액을 잃게 됩니다" << endl;

		firstCard = card[cardCount-1];
		cardCount--;
		secondCard = card[cardCount-1];
		cardCount--;

		cout << endl;
		cout << endl;

		//딜러 카드 드로우
		cout << "첫번째 카드 : " << firstCard / 4 + 1;
		switch (firstCard % 4) {
			case 0: cout << "♠"; break;
			case 1: cout << "◆"; break;
			case 2: cout << "♥"; break;
			case 3: cout << "♣"; break;
		}
		cout << endl;
		cout << "두번째 카드 : " << secondCard / 4 + 1;
		switch (secondCard % 4) {
			case 0: cout << "♠"; break;
			case 1: cout << "◆"; break;
			case 2: cout << "♥"; break;
			case 3: cout << "♣"; break;
		}
		cout << endl;
		cout << endl;

		//현 상황 확인
		cout << "남은 카드 : " << cardCount << endl;
		cout << "남은 돈 : " << haveMoney << "원" << endl;
		
		
		//배팅여부 확인
		cout << "배팅하시겠습니까? (예 : 1, 아니오 : 2) : ";
		input = 0;
		while (input == 0){
			cin >> input;
			if (input == 1 || input == 2)
			{
				break;
			}
			else {
				cout << "잘못 입력하셨습니다. 다시 입력해주세요 (예 : 1, 아니오 : 2) : ";
				input = 0;
			}
		}

		//배팅액 확인
		if (input == 1) {
			cout << "배팅액을 입력해주세요 (최소 10000) : ";
			input = 0;
			while (input == 0) {
				cin >> input;
				if (input > haveMoney)
				{
					cout << "금액을 초과했습니다. 다시 입력해주세요 : ";
					input = 0;
					continue;
				}
				else if (input < 10000) {
					cout << "최소배팅액 미달입니다. 다시 입력해주세요 : ";
					input = 0;
					continue;
				}
				else if (input >= 10000) {
					betMoney = input;
					break;
				}
			}


			//나의 카드 드로우
			myCard = card[cardCount - 1];
			cardCount--;
			cout << "나의 카드 : " << myCard / 4 + 1;
			switch (myCard % 4) {
				case 0: cout << "♠"; break;
				case 1: cout << "◆"; break;
				case 2: cout << "♥"; break;
				case 3: cout << "♣"; break;
			}
			cout << endl;

			//승패 확인
			if (((myCard / 4 + 1) > (firstCard / 4 + 1) && (myCard / 4 + 1) < (secondCard / 4 + 1)) || (myCard / 4 + 1) < (firstCard / 4 + 1) && (myCard / 4 + 1) > (secondCard / 4 + 1)) {
				cout << "승리! 배팅액만큼의 돈을 얻습니다!";				
				haveMoney += betMoney;
				cout << "남은 돈 : " << haveMoney << "원" << endl;
			}
			else {
				cout << "패배. 배팅액만큼의 돈을 잃습니다!" << endl;
				haveMoney -= betMoney;
				cout << "남은 돈 : " << haveMoney << "원" << endl;
			}

		}

		//배팅 포기
		else if (input == 2) {
			cout << "폴드. 최소배팅액을 잃습니다." << endl;
			haveMoney -= 10000;
			cout << "남은 돈 : " << haveMoney << "원" << endl;
		}

		//덱 고갈 시 게임 종료
		if (cardCount <= 2){
			cout << "카드가 다 떨어졌습니다. 수고하셨습니다." << endl;
			break;		
		}
		//소지금이 최소 배팅엑 미만일 시 게임 종료
		if (haveMoney < 10000) {
			cout << "파산하셨습니다. 하하하." << endl;
			break;
		}

		//재도전 여부 확인
		cout << "다시 도전하시겠습니까? (예 : 1, 아니오 : 2) : ";
		input = 0;
		while (input == 0) {
			cin >> input;
			if (input == 1 || input == 2)
			{
				break;
			}
			else {
				cout << "잘못 입력하셨습니다. 다시 입력해주세요 (예 : 1, 아니오 : 2) : ";
				input = 0;
			}
		}

		if (input == 1)
			system("cls");
		else if (input == 2)
			break;
	}	

}
