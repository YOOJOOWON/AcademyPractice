#include<iostream>
#include<time.h>
#include<windows.h>
#include <cstdlib>

using namespace std;

struct playerData {
	char name[99];
	int level;
	long long hp;
	long long atk;
	long long def;
	long long spd;
	int life;
	double atkTrain;
	double defTrain;
	double spdTrain;
};

struct enemyData {
	int num;
	long long hp;
	long long atk;
	long long def;
	long long spd;
};


void wait() {
	int count = 0;
	while (count < 500000000) { count++; }
}

void text(char text[]) {
	cout << text << endl;
	wait();
}


void bwait() {
	int count = 0;
	while (count < 100000000) { count++; }
}

void btext(char text[]) {
	cout << text << endl;
	bwait();
}

void battle(struct playerData *player, struct enemyData *enemy)
{
	bool runSuccess = false;
	bool yourTurn = true;
	bool nowDefend = false;
	long long damage;
	while (true) {
		if (player->atkTrain > (player->atk) + 1)
		{
			player->atk = (int)player->atkTrain;
			btext("������ ���� �� ���п� ����ġ�� �׿���.");
			btext("���ݷ��� ����ߴ�.");
		}
		if (player->defTrain > (player->def) + 1)
		{
			player->def = (int)player->defTrain;
			btext("����� ���� �� ���п� ����ġ�� �׿���.");
			btext("������ ����ߴ�.");
		}
		if (player->spdTrain > (player->spd) + 1)
		{
			player->spd = (int)player->spdTrain;
			btext("������ ���� ģ ���п� ����ġ�� �׿���.");
			btext("�ӵ��� ����ߴ�.");
		}

		cout << endl;
		cout << enemy -> num << "��° ���� ��Ÿ����." << endl;

		cout << "* ���� ��� : " << player->life << endl;
		cout << endl;
		cout << player->name << endl;
		cout << "����� ü�� : " << player->hp << endl;
		cout << "����� ���ݷ� : " << player->atk << endl;
		cout << "����� ���� : " << player->def << endl;
		cout << "����� �ӵ� : " << player->spd << endl;
		cout << "------------------------" << endl;

		cout << enemy->num << "�� ����" << endl;
		cout << "���� ü�� : " << enemy->hp << endl;
		cout << "���� ���ݷ� : " << enemy->atk << endl;
		cout << "���� ���� : " << enemy->def << endl;
		cout << "���� �ӵ� : " << enemy->spd << endl;
		text("");

		int turn = 0;
		int prob = rand() % 4;
		//�÷��̾� ��
		if (yourTurn) {
			btext("����� ���Դϴ�.");
			cout << "������ �Ͻðڽ��ϱ�? 1. ����, 2. ���, 3. ����" << endl;

			while (!(cin >> turn)) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "��? ������?" << endl;
			}
			switch (turn)
			{
			case 1:
				damage = player->atk - enemy->def;
				if (damage > 0) {
					btext("����� ����.");
					if (prob != 0) {
						player->atkTrain += 0.5;
						player->atkTrain *= 1.1;
						enemy->hp -= damage;
						cout << damage; text("�� �������� ������.");
					}
					else {
						player->atkTrain += 0.5;
						player->atkTrain *= 1.5;
						enemy->hp -= damage * 2;
						btext("ġ��Ÿ! ������ 10��!"); cout << damage * 10; text("�� �������� ������.");
					}
				}
				else {
					btext("������ 0...");
					text("�ƹ� ȿ���� ���� �� �ϴ�");
				}
				break;
			case 2:
				player->defTrain += 0.5;
				player->defTrain *= 1.1;
				text("���и� ���÷ȴ�. �̹� �Ͽ� ���� 100�� ���.");
				nowDefend = true;
				break;
			case 3:
				player->spdTrain += 0.5;
				player->spdTrain *= 1.1;
				if (player->spd > enemy->spd) {
					if (prob != 0) {
						enemy->atk /= 2;
						enemy->def /= 2;
						btext("����ġ�µ� �����ߴ�.");
						btext("���� �ǿ��� ��������.");
						btext("���� ���ݷ� �ݰ�.");
						text("���� ���� �ݰ�.");
						runSuccess = true;
					}
					else {
						btext("������ �������� ������.");
						text("����ġ�� ����");
					}
				}
				else {
					btext("�ӵ��� �����ϴ�.");
					text("����ġ���� ������ ���������� ���Ҵ�.");
				}
				break;
			default:
				text("ȥ���� ���� ����� �̻��� ���� �ϱ� �����ߴ�.");
				break;
			}
			yourTurn = false;
			system("cls");
			if (player->hp <= 0 || enemy->hp <= 0 || runSuccess)
				break;
		}
		else {
			btext("���� ���Դϴ�.");
			btext("���� ����.");
			if (!nowDefend)
				damage = enemy->atk - player->def;
			else
				damage = enemy->atk - (player->def * 100);
			if (damage > 0)
			{
				if (prob != 0) {
					player->hp -= damage;
					cout << damage; text("�� �������� �Ծ���.");
				}
				else {
					player->hp -= damage * 2;
					btext("ġ��Ÿ! ������ 2��!"); cout << damage * 2; text("�� �������� �Ծ���.");
				}
			}
			else if (damage <= 0 && damage > -10){
				text("������ 0. �ƹ� ȿ���� ���� �� �ϴ�");
			}
			else if (damage <= -10)
			{
				enemy->hp += damage;
				btext("�ܴ��� ���!");
				text("������ ��뿡�� �������� �־���!");
			}
			yourTurn = true;
			system("cls");
			if (player->hp <= 0 || enemy->hp <= 0 || runSuccess)
				break;
		}
	}
}

void main(void) {

	struct playerData player;
	player.level = 1;
	player.hp = 1;
	player.atk = 1;
	player.def = 1;
	player.spd = 1;
	player.life = 999;
	player.atkTrain = 1;
	player.defTrain = 1;
	player.spdTrain = 1;

	struct playerData *play = &player;
	

	struct enemyData enemyList[6];
	struct enemyData *enemList[6];

	for (int i = 1; i <= 6; i++) {
		enemyData enemy;
		enemy.num = i;
		enemy.hp = (i+1) * i * i * i * i * i * i * 111;
		enemy.atk = i * i * i * i * i * i* 111;
		enemy.def = (i-1) * i * i * i * i * i * 111;
		enemy.spd = (i-1) * i * i * i * i * i * 111;
		enemyList[i - 1] = enemy;
		enemList[i - 1] = &enemyList[i - 1];
	}


	cout << "����� �̸��� �Է����ּ��� : ";
	cin >> player.name;
	system("cls");
	
	int count = 0;
	while (count < 350)
	{
		for (int i = 0; i < 8; i++)
			cout << "��� x 999";
		cout << endl;
		count++;
	}
	system("cls");
		
	text("�ȳ��ϼ���.");
	text(player.name);
	text("");
	text("����� ���ռ��� �����߽��ϴ�.");
	text("");
	text("����� ��� ������ �ΰ��� ��������,");
	text("��ſ��Դ� �������� �پ �γ��� ���,");
	text("�׸��� �ΰ����μ��� ������ ���� ���Դϴ�.");
	text("");
	text("������ �������κ��� ������ ���� �� �ִ� ����� ��� ��.");
	text("�� �ڸ�����, ���� ��� ���Դϴ�.");
	text("");
	text("��, �׷� ���ռ��� ���ðڽ��ϱ�?");
	text("1. ����, 2. ����, 3. ����, 4. ����");

	int input;
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "��? ������?" << endl;
	}
	system("cls");

	if (input > 0 && input < 5) {
		text("�Ǹ��Ͻʴϴ�. �׷� ���ռ��� ���� ���ڽ��ϴ�.");
		text("");
		text("��? �������� �ϳ� �ۿ� ���� �ʾҳİ��?");
		text("����, �߸� ���̰���. ��� ſ�̿���.");
	}
	else {
		text("�Ǹ��Ͻʴϴ�. �׷� ���ռ��� ���� ���ڽ��ϴ�.");
		text("");
		text("��? �ڱ�� ������ �߿� ���� �ʾҴٰ��?");
		text("����, ���� ���� �͸�ŭ�̳� ��㵵 ���Ͻó׿�.");
	}

	text("");
	system("cls");
	text("��, ���� ������ �����ϰڽ��ϴ�.");
	text("");
	text("��, ����� ����� ���� �������ͽ��� �˷��帮�ڽ��ϴ�.");
	text("");
	text("����� ������,");
	text("	1 �Դϴ�.");
	text("");
	text("����� ü����,");
	text("	1 �Դϴ�.");
	text("");
	text("����� ���ݷ���,");
	text("	1 �Դϴ�.");
	text("");
	text("����� ������,");
	text("��� �͵� ����,");
	text("	1 �Դϴ�.");

	text("");
	system("cls");
	text("�����ƿ�. ������ �� �������� �Ǵϱ��.");
	text("");
	text("��, �����,");
	text("������ ��� ������,");
	text("	999 �Դϴ�.");
	text("");
	text("���� ���� ������?");
	text("");

	system("cls");

	text("�׷�,");
	text("����� ���ϴ�.");

	system("cls");

	int enemyCount = 0;
	int baseHP = play->hp;
	while (enemyCount < 6) {
		battle(play, enemList[enemyCount]);

		if (play -> hp <= 0)
		{
			btext("����� �׾����ϴ�.");
			player.hp = baseHP;
			player.life--;

			if (play->life <= 0) {
				text("�����ִ� ����� �����ϴ�.");
				text("");
				text("GAME OVER");
				return;
			}
			
			btext("�絵���մϴ�.");
		}
		if (enemList[enemyCount]->hp <= 0) {
			play-> level *= 2;
			play-> atk *= 2;
			play-> atkTrain *= 2;
			play-> def *= 2;
			play-> defTrain *= 2;
			play-> spd *= 2;
			play-> spdTrain *= 2;
			play->hp += 1000;
			baseHP = play->hp;
			
			text("���� ����Ʈ�Ƚ��ϴ�");
			btext("������.");
			btext("���ݷ� 2�� ��");
			btext("���� 2�� ��");
			btext("�ӵ� 2�� ��");
			btext("ü�� 1000 ��");
			text("");
			text("");
			system("cls");
			enemyCount++;
		}
	}
	
	system("cls");
	text("¦");
	text("¦");
	text("¦");
	text("");
	text("�Ǹ��մϴ�.");
	text("");
	text("������ ������ ����̱���.");
	text("������, ���⼭ ���� �ƴմϴ�.");
	text("������ �̺��� �� ���ϴϱ��.");
	text("");
	text("����ϼ���.");
	text(""); 
	text("...�Ƹ���.");
	text("");
	text("���� �ð��� �ȴٸ� ������.");
	text("�׷�,");
	text("�̸�.");
	text("");
	text("To be Continued...");


}
