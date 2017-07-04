#include <iostream>

using namespace std;

void main(void) {

	//변수
	//변하는 수

	//정수형 타입
	//변수타입				크기					범위
	//int					4Byte				~21억 ~ 21억
	//unsigned int			4Byte				0 ~ 43억
	//long					4Byte				~21억 ~ 21억
	//unsigned long			4Byte				0 ~ 43억
	//short					2Byte				-32767 ~ 32768
	//unsigned short		2Byte				0 ~ 65335
	//

	//실수형 타입
	//실수타입				크기					범위
	//float					4Byte				소수점 6자리
	//double				8Byte				소수점 15자리
	//

	//문자형 타입
	//char					1Byte				정수
	//unsigned char			1Byte				양의 정수
	//

	//참,거짓
	//bool					1Byte				0이면 거짓, 1이면 참

	//변수선언시 유의할 점
	//1. 변수는 같은 이름으로 중복선언이 안된다.
	//2. 변수는 선언하면 쓰레기값을 가지고 있으므로 초기화가 꼭 필요하다.
	//3. 변수 선언시 숫자가 먼저 올 수 없다 (ex) int 1player = 100;
	//4. 변수 선언시 되도록 영어로
	//5. 변수는 누가 봐도 어떤 용도로 사용되는지 명확하게 파악할 수 있게


	//변수표기법
	//1. 헝가리안 표기법
	//절차지향적 코딩이 유행할 때 작업속도를 올리고자 나온 표기법
	//MS에서 개발되었는데 2012년 이후에는 표기금지가 되었다
	//구시대 유물
	// 특징은 변수타입의 약칭을 변수 앞에 붙이는 게 특징
	//예) in num -> int nNum


	//2. 카멜 표기법
	// 객채지향 코딩이 나오면서 코드의 줄 수가 짧아짐
	//가독성을 높이기 위해 첫글자는 대문자로 표기했는데
	//낙타 혹처럼 생겨서 카멜... ㅡㅡ

	int playerHP = 500;
	int playerMP = 50;
	int playerAttk = 30;
	float playerCritical = 1.5;
	bool playerIsAlive = true;

	cout << "플레이어의 체력 : " << playerHP << endl;
	cout << "플레이어의 마력 : " << playerMP << endl;
	cout << "플레이어의 공격력 : " << playerAttk << endl;
	cout << "플레이어의 크리티컬 배율 : " << playerCritical << endl;
	cout << "플레이어의 생존 여부 : " << playerIsAlive << endl;

}	