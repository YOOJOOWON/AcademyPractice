#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;


void main(void) {

	//����
	//1. strtok -> ���⸶�� ������ ���
	
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

	//2. ��Ŀī��
	//	ī�� 2�� ��ο�. �� �� ����
	//	������ : 100����
	//	����(�ּұݾ� 10000)
	//  �� ī�� ������ ���ڰ� ������ �¸�. ���þ��� 2�� ����. �ƴϸ� �й�.

	srand(time(NULL));

	int card[52];
	int haveMoney = 1000000;
	int betMoney = 0;
	int cardCount = 0;

	int input = 0;

	//ī�带 ���� �ִ´�
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
		cardCount++;
	}

	//�� ����
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
		cout << "�ų��� ����ִ� ī�����" << endl;
		cout << "�� ���� ī�带 �ո����� �����ϴ�." << endl;
		cout << "�� ���� ������ �� �� �� �� ���մϴ�.(�ּҹ��þ� 10000��)" << endl;
		cout << "������ �� ��� ������ �� ���� �� �����ϴ�. " << endl;
		cout << "�� ī���� ���ڰ� �� ī���� ���� ���̿� �̱� ��� �¸�, ���þ��� 2�踦 �޽��ϴ�." << endl;
		cout << "�� ī���� ���� ������ �������� ��� ��� �й�, ���þ��� �ҽ��ϴ�." << endl;
		cout << "�ºθ� ������ ���, �ּҹ��þ��� �Ұ� �˴ϴ�" << endl;

		firstCard = card[cardCount-1];
		cardCount--;
		secondCard = card[cardCount-1];
		cardCount--;

		cout << endl;
		cout << endl;

		//���� ī�� ��ο�
		cout << "ù��° ī�� : " << firstCard / 4 + 1;
		switch (firstCard % 4) {
			case 0: cout << "��"; break;
			case 1: cout << "��"; break;
			case 2: cout << "��"; break;
			case 3: cout << "��"; break;
		}
		cout << endl;
		cout << "�ι�° ī�� : " << secondCard / 4 + 1;
		switch (secondCard % 4) {
			case 0: cout << "��"; break;
			case 1: cout << "��"; break;
			case 2: cout << "��"; break;
			case 3: cout << "��"; break;
		}
		cout << endl;
		cout << endl;

		//�� ��Ȳ Ȯ��
		cout << "���� ī�� : " << cardCount << endl;
		cout << "���� �� : " << haveMoney << "��" << endl;
		
		
		//���ÿ��� Ȯ��
		cout << "�����Ͻðڽ��ϱ�? (�� : 1, �ƴϿ� : 2) : ";
		input = 0;
		while (input == 0){
			cin >> input;
			if (input == 1 || input == 2)
			{
				break;
			}
			else {
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� (�� : 1, �ƴϿ� : 2) : ";
				input = 0;
			}
		}

		//���þ� Ȯ��
		if (input == 1) {
			cout << "���þ��� �Է����ּ��� (�ּ� 10000) : ";
			input = 0;
			while (input == 0) {
				cin >> input;
				if (input > haveMoney)
				{
					cout << "�ݾ��� �ʰ��߽��ϴ�. �ٽ� �Է����ּ��� : ";
					input = 0;
					continue;
				}
				else if (input < 10000) {
					cout << "�ּҹ��þ� �̴��Դϴ�. �ٽ� �Է����ּ��� : ";
					input = 0;
					continue;
				}
				else if (input >= 10000) {
					betMoney = input;
					break;
				}
			}


			//���� ī�� ��ο�
			myCard = card[cardCount - 1];
			cardCount--;
			cout << "���� ī�� : " << myCard / 4 + 1;
			switch (myCard % 4) {
				case 0: cout << "��"; break;
				case 1: cout << "��"; break;
				case 2: cout << "��"; break;
				case 3: cout << "��"; break;
			}
			cout << endl;

			//���� Ȯ��
			if (((myCard / 4 + 1) > (firstCard / 4 + 1) && (myCard / 4 + 1) < (secondCard / 4 + 1)) || (myCard / 4 + 1) < (firstCard / 4 + 1) && (myCard / 4 + 1) > (secondCard / 4 + 1)) {
				cout << "�¸�! ���þ׸�ŭ�� ���� ����ϴ�!";				
				haveMoney += betMoney;
				cout << "���� �� : " << haveMoney << "��" << endl;
			}
			else {
				cout << "�й�. ���þ׸�ŭ�� ���� �ҽ��ϴ�!" << endl;
				haveMoney -= betMoney;
				cout << "���� �� : " << haveMoney << "��" << endl;
			}

		}

		//���� ����
		else if (input == 2) {
			cout << "����. �ּҹ��þ��� �ҽ��ϴ�." << endl;
			haveMoney -= 10000;
			cout << "���� �� : " << haveMoney << "��" << endl;
		}

		//�� �� �� ���� ����
		if (cardCount <= 2){
			cout << "ī�尡 �� ���������ϴ�. �����ϼ̽��ϴ�." << endl;
			break;		
		}
		//�������� �ּ� ���ÿ� �̸��� �� ���� ����
		if (haveMoney < 10000) {
			cout << "�Ļ��ϼ̽��ϴ�. ������." << endl;
			break;
		}

		//�絵�� ���� Ȯ��
		cout << "�ٽ� �����Ͻðڽ��ϱ�? (�� : 1, �ƴϿ� : 2) : ";
		input = 0;
		while (input == 0) {
			cin >> input;
			if (input == 1 || input == 2)
			{
				break;
			}
			else {
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� (�� : 1, �ƴϿ� : 2) : ";
				input = 0;
			}
		}

		if (input == 1)
			system("cls");
		else if (input == 2)
			break;
	}	

}
