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

	//ù �ڸ��� 0�� �ƴϰ�, ���� �ߺ����� �ʴ� ���ڸ� ����
	c1 = rand() % 10;
	while (c1 == 0) { c1 = rand() % 10; }
	c2 = rand() % 10;
	while (c2 == c1) { c2 = rand() % 10;}
	c3 = rand() % 10;
	while (c3 == c1 || c3 == c2) { c3 = rand() % 10; }
	

	cout << "�ų��� ����ִ� ���̽��� ����~" << endl;
	cout << "���� �ٸ� �� �ڸ� ���ڸ� �Է��Ͽ� ���� ������ ���ߴ� �����Դϴ�." << endl;
	cout << "�ڸ��� �ٸ����� ���ڰ� ���� ��� ��(B)." << endl;
	cout << "�ڸ��� ���� ���ڵ� ���� ��� ��Ʈ����ũ(S)." << endl;
	cout << "�ڸ��� ���� �� �� �ٸ� ��쿡�� �ƿ�(Out) �Դϴ�." << endl;
	
	while (countChance > 0)
	{
		countBall = 0;
		countStrike = 0;
		cout << "���ڸ� �Է��ϼ��� (���� ȸ�� " << countChance << "��) : ";

		cin >> input;
		p1 = input / 100;
		p2 = input % 100 / 10;
		p3 = input % 10;

		// �߸� �Է��� ����� ����ó��
		if (input < 100 || input >= 1000) {
			cout << "�ش� ������ ��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		if (p1 == 0) {
			cout << "ù �ڸ����� 0�� �� �� �����ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		if (p1 == p2 || p2 == p3 || p3 == p1) {
			cout << "�� �ڸ��� ���� �ٸ� ���ڰ� �ƴմϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}

		// �� ������ ��Ʈ����ũ, �� ����
		if (p1 == c1) { countStrike++; }
		if (p2 == c2) { countStrike++; }
		if (p3 == c3) { countStrike++; }
		if (p1 == c2) { countBall++; }
		if (p1 == c3) { countBall++; }
		if (p2 == c1) { countBall++; }
		if (p2 == c3) { countBall++; }
		if (p3 == c1) { countBall++; }
		if (p3 == c2) { countBall++; }
		
		// 3��Ʈ����ũ�� ����. break�� ������ ��������.
		if (countStrike == 3) {
			cout << "�����Դϴ�! ���� " << input << "�Դϴ�." << endl;
			break;
		}
		// �� ���� ��� ����ó��. Ball, Strike, Out�� �˷��ְ� ���� ȸ�� 1 ���δ�.
		else {
			cout << "�����Դϴ�. ";
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
			cout << "��ȸ�� ��� �����ϼ̽��ϴ�. �� ������ �ѻ�." << endl;
	}


}
