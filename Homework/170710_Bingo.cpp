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

	//1~25 �Է�
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			bingo[i][j] = (i * 5) + (j + 1);

	//����
	for (int i = 0; i < 50; i++) {
		dest = rand() % 25;
		sour = rand() % 25;
		temp = bingo[dest / 5][dest % 5];
		bingo[dest / 5][dest % 5] = bingo[sour / 5][sour % 5];
		bingo[sour / 5][sour % 5] = temp;
	}

	

	while (true) {
		//ȭ�� ���
		cout << "��̰� �ų��� ���� ����~" << endl;
		cout << "�� ���ڸ� �Է��Ͽ� #���� üũ�մϴ�." << endl;
		cout << "����, ����, �밢�� ���� #���� �����ϸ� ����!" << endl;
		cout << "3���� �ϼ��Ǹ� ������ �����մϴ�." << endl;
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

		//�¸�����
		if (bingoCount > 4)
		{
			cout << "�����մϴ�! 5���� �ϼ�!" << endl;
			break;
		}

		cout << "���� ���� : " << bingoCount << endl;
		cout << "���ڸ� �Է��ϼ��� : ";


		//���� ���� �Է� ����
		while (!(cin >> input)) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�. ���ڸ� �Է����ּ��� : ";
		}
		//������ ������ ��� �Է� ����
		if (input < 1 || input > 25) {
			cout << "�ش� ������ ��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
			system("cls");
			continue;
		}

		//�Է��� ���ڸ� #(0)���� üũ
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				if (bingo[i][j] == input)
					bingo[i][j] = -1;
			}
			cout << endl;
		}

		//���� Ȯ��
		//����
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
		//����
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
		//�밢��
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
