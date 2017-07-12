#include<iostream>
#include<time.h>
using namespace std;
//한 변수의 집합 -> 배열
//여러 변수의 집합 -> 구조체

void main(void) {
	//문자열 함수
	// 1. strlen == string length

	char* toto = "가나다라";
	cout << toto + 1 << endl;

	char str[10] = "pikachu";

	int num = strlen(str);

	cout << "길이는 : " << num << endl;;

	// 2. strcmp
	// 문자열의 크기를 비교하는 함수
	// 왼쪽이 크면 1, 오른쪽이 크면 -1, 같으면 0을 반환한다

	char str1[10] = "acd";
	char str2[10] = "abe";

	int num2 = strcmp(str1, str2);

	cout << "비교값 : " << num2 << endl;

	// 3. strcat
	// 문자열 이어붙이기
	// strcat(문자열1, 문자열2)
	// 문자열1에 문자열2를 이어붙여준다
	// 당연히 문자열1의 버퍼값은 넉넉해야한다

	char str3[32] = "I am";
	char str4[10] = " Hungry";

	strcat(str3, str4);
	cout << str3 << endl;

	// 4. strcpy
	// 문자열 복사
	// strcpy(문자열1, 문자열2)
	// 문자열2를 문자열1에 복사해준다

	char str5[10];
	char str6[10] = "Pokemon";

	strcpy(str5, str6);
	cout << str5 << endl;

	//룰!
	//1. 문자열을 입력받는다(무조건)
	//2. 입력받은 문자열이 거꾸로 출력된다
	//3. printf, scanf

	char test[128];
	printf("문자열을 입력받는다 입력해봐라 : ");
	scanf("%s", &test);

	for (int i = strlen(test); i > 0; i--)
	{
		cout << test[i - 1];
	}
	for (int i = 0; i < strlen(test)/2; i++)
	{
		char temp;
		temp = test[i];
		test[i] = test[strlen(test) - i - 1];
		test[strlen(test) - i - 1] = temp;
	}

	cout << test << endl;

	//룰
	// 1. 문자열을 입력받는다
	// 2. 입력받은 문자열의 짝수번째만 거꾸로 출력된다
	// 예) abcde -> adcbe

	char test2[128];
	printf("문자열을 입력받는다 입력해봐라 : ");
	scanf("%s", &test2);

	for (int i = 0; i < strlen(test2); i++)
	{
		if (i % 2 == 0)
			cout << test2[i];
		else
			cout << test2[strlen(test2)-i-1];
	}
	cout << endl;


	//과제
	//1. strtok -> 띄어쓰기마다 나눠서 출력
	//2. 포커카드
	//	카드 2장 드로우. 그 후 배팅
	//	소지금 : 100만원
	//	배팅(최소금액 10000)
	//  두 카드 사이의 숫자가 나오면 승리. 배팅액의 2배 지급. 아니면 패배.
}

