#include <iostream>
#include <time.h>

using namespace std;

void main(void) {

	// 1. if, else

	//int girlAge;
	//cout << "입력해보시오 : ";
	//cin >> girlAge;
	//if (girlAge < 20)
	//	cout << "경찰 아저씨 여기에요!" << endl;
	//else if (girlAge >= 20 && girlAge <= 24)
	//	cout << "나이스!" << endl;
	//else if (girlAge > 24 && girlAge < 28)
	//	cout << "커버 가능!" << endl;
	//else
	//	cout << "안돼......" << endl;

	//int skillDamage;
	//int enemyHP = 50;
	//
	//cout << "오크가 나타났다! 오크의 체력 : " << enemyHP << endl;
	//cout << "사용할 스킬의 데미지를 입력하시오 : ";
	//cin >> skillDamage;
	//enemyHP -= skillDamage;
	//if (enemyHP <= 0)
	//	cout << skillDamage << "의 데미지! 오크는 쓰러졌다!" << endl;
	//else
	//	cout << "오크는 체력 " << enemyHP << "을 남기고 살아있다. 망했다......" << endl;


	//2. swithch

	//cout << "디아블로의 세계에 온 것을 환영한다~" << endl;
	//cout << "직업을 골라라~" << endl;
	//cout << "1. 바바리안, 2. 소서리스, 3. 네크로맨서, 4. 팔라딘, 5. 아마존" << endl;
	//
	//int selectNum;
	//
	//cin >> selectNum;
	//
	//switch (selectNum) {
	//case 1 :
	//	cout << "바바리안을 선택했다!" << endl;
	//	break;
	//case 2:
	//	cout << "소서리스를 선택했다!" << endl;
	//	break;
	//case 3:
	//	cout << "네크로맨서를 선택했다!" << endl;
	//	break;
	//case 4:
	//	cout << "팔라딘을 선택했다!" << endl;
	//	break;
	//case 5:
	//	cout << "아마존을 선택했다!" << endl;
	//	break;
	//}


	//char skillInput;
	//cout << "너는 롤의 챔피온 아리다." << endl;
	//cout << "적 챔피온을 만났다! 스킬을 사용해라" << endl;
	//cout << "q: 현혹의 구슬, w: 여우불, e: 매혹, r: 혼령질주" << endl;
	//cout << "사용할 스킬을 입력하시오 : ";
	//cin >> skillInput;
	//switch (skillInput) {
	//case 'q':
	//	cout << "현혹의 구슬!" << endl;
	//	break;
	//case 'w':
	//	cout << "여우불!" << endl;
	//	break;
	//case 'e':
	//	cout << "매혹!" << endl;
	//	break;
	//case 'r':
	//	cout << "궁극기 혼령질주!" << endl;
	//	break;
	//default:
	//	cout << "키보드 잘못 눌렀다. 망했다..." << endl;
	//	break;
	//}


	// 예시 : 가위바위보
	
	//컴퓨터는 랜덤하게 0 ~ 2의 값을 받는다
	//0은 주먹, 1은 가위, 2는 보자기라고 가정한다
	//플레이어도 0 ~ 2 중에서 고를 수 있다
	//컴퓨터가 뭘 냈는지, 플레이어가 뭘 냈는지 출력하고
	//승/무/패 를 표시해라


	srand(time(NULL));

	cout << "가위바위보 승부다. 가위, 바위, 보! : " << endl;
	cout << "입력 (0: 바위, 1, 가위, 2 보) : ";
	int myChoice;
	int yourChoice = rand() % 3;
	cin >> myChoice;

	
	if (myChoice == yourChoice)
		cout << "무승부!" << endl;
	else
		switch (myChoice) {
		case 0: //바위
			cout << "당신의 선택은 바위입니다." << endl;
			cout << "컴퓨터의 선택은 ";
			if (yourChoice == 1) {
				cout << "가위입니다." << endl;
				cout << "당신의 승리!" << endl;
			}
			else {
				cout << "보입니다." << endl;
				cout << "컴퓨터의 승리!" << endl;
			}
		break; 
		case 1: //가위
			cout << "당신의 선택은 가위입니다." << endl;
			cout << "컴퓨터의 선택은 ";
			if (yourChoice == 2) {
				cout << "보입니다." << endl;
				cout << "당신의 승리!" << endl;
			}
			else {
				cout << "바위입니다." << endl;
				cout << "컴퓨터의 승리!" << endl;
			}
		break; 
		case 2: //보
			cout << "당신의 선택은 보입니다." << endl;
			cout << "컴퓨터의 선택은 ";
			if (yourChoice == 0) {
				cout << "바위입니다." << endl;
				cout << "당신의 승리!" << endl;
			}
			else {
				cout << "가위입니다." << endl;
				cout << "컴퓨터의 승리!" << endl;
			}
		break; 
		}
		

}