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
			btext("공격을 많이 한 덕분에 수련치가 쌓였다.");
			btext("공격력이 상승했다.");
		}
		if (player->defTrain > (player->def) + 1)
		{
			player->def = (int)player->defTrain;
			btext("방어을 많이 한 덕분에 수련치가 쌓였다.");
			btext("방어력이 상승했다.");
		}
		if (player->spdTrain > (player->spd) + 1)
		{
			player->spd = (int)player->spdTrain;
			btext("도망을 많이 친 덕분에 수련치가 쌓였다.");
			btext("속도가 상승했다.");
		}

		cout << endl;
		cout << enemy -> num << "번째 적이 나타났다." << endl;

		cout << "* 남은 목숨 : " << player->life << endl;
		cout << endl;
		cout << player->name << endl;
		cout << "당신의 체력 : " << player->hp << endl;
		cout << "당신의 공격력 : " << player->atk << endl;
		cout << "당신의 방어력 : " << player->def << endl;
		cout << "당신의 속도 : " << player->spd << endl;
		cout << "------------------------" << endl;

		cout << enemy->num << "의 괴물" << endl;
		cout << "적의 체력 : " << enemy->hp << endl;
		cout << "적의 공격력 : " << enemy->atk << endl;
		cout << "적의 방어력 : " << enemy->def << endl;
		cout << "적의 속도 : " << enemy->spd << endl;
		text("");

		int turn = 0;
		int prob = rand() % 4;
		//플레이어 턴
		if (yourTurn) {
			btext("당신의 턴입니다.");
			cout << "무엇을 하시겠습니까? 1. 공격, 2. 방어, 3. 도망" << endl;

			while (!(cin >> turn)) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "네? 뭐라고요?" << endl;
			}
			switch (turn)
			{
			case 1:
				damage = player->atk - enemy->def;
				if (damage > 0) {
					btext("당신의 공격.");
					if (prob != 0) {
						player->atkTrain += 0.5;
						player->atkTrain *= 1.1;
						enemy->hp -= damage;
						cout << damage; text("의 데미지를 입혔다.");
					}
					else {
						player->atkTrain += 0.5;
						player->atkTrain *= 1.5;
						enemy->hp -= damage * 2;
						btext("치명타! 데미지 10배!"); cout << damage * 10; text("의 데미지를 입혔다.");
					}
				}
				else {
					btext("데미지 0...");
					text("아무 효과도 없는 듯 하다");
				}
				break;
			case 2:
				player->defTrain += 0.5;
				player->defTrain *= 1.1;
				text("방패를 들어올렸다. 이번 턴에 방어력 100배 상승.");
				nowDefend = true;
				break;
			case 3:
				player->spdTrain += 0.5;
				player->spdTrain *= 1.1;
				if (player->spd > enemy->spd) {
					if (prob != 0) {
						enemy->atk /= 2;
						enemy->def /= 2;
						btext("도망치는데 성공했다.");
						btext("적의 의욕이 떨어진다.");
						btext("적의 공격력 반감.");
						text("적의 방어력 반감.");
						runSuccess = true;
					}
					else {
						btext("적에게 움직임을 읽혔다.");
						text("도망치기 실패");
					}
				}
				else {
					btext("속도가 부족하다.");
					text("도망치려고 했지만 따라잡히고 말았다.");
				}
				break;
			default:
				text("혼란에 빠진 당신은 이상한 짓을 하기 시작했다.");
				break;
			}
			yourTurn = false;
			system("cls");
			if (player->hp <= 0 || enemy->hp <= 0 || runSuccess)
				break;
		}
		else {
			btext("적의 턴입니다.");
			btext("적의 공격.");
			if (!nowDefend)
				damage = enemy->atk - player->def;
			else
				damage = enemy->atk - (player->def * 100);
			if (damage > 0)
			{
				if (prob != 0) {
					player->hp -= damage;
					cout << damage; text("의 데미지를 입었다.");
				}
				else {
					player->hp -= damage * 2;
					btext("치명타! 데미지 2배!"); cout << damage * 2; text("의 데미지를 입었다.");
				}
			}
			else if (damage <= 0 && damage > -10){
				text("데미지 0. 아무 효과도 없는 듯 하다");
			}
			else if (damage <= -10)
			{
				enemy->hp += damage;
				btext("단단한 방어!");
				text("오히려 상대에게 데미지를 주었다!");
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


	cout << "당신의 이름을 입력해주세요 : ";
	cin >> player.name;
	system("cls");
	
	int count = 0;
	while (count < 350)
	{
		for (int i = 0; i < 8; i++)
			cout << "용사 x 999";
		cout << endl;
		count++;
	}
	system("cls");
		
	text("안녕하세요.");
	text(player.name);
	text("");
	text("당신은 마왕성에 도착했습니다.");
	text("");
	text("당신은 비록 나약한 인간의 몸이지만,");
	text("당신에게는 누구보다 뛰어난 인내와 용기,");
	text("그리고 인간으로서의 긍지가 있을 것입니다.");
	text("");
	text("마왕의 위협으로부터 세상을 구할 수 있는 사람은 당신 뿐.");
	text("이 자리에서, 오직 당신 뿐입니다.");
	text("");
	text("자, 그럼 마왕성에 들어가시겠습니까?");
	text("1. 들어간다, 2. 들어간다, 3. 들어간다, 4. 들어간다");

	int input;
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "네? 뭐라고요?" << endl;
	}
	system("cls");

	if (input > 0 && input < 5) {
		text("훌륭하십니다. 그럼 마왕성의 문을 열겠습니다.");
		text("");
		text("네? 선택지가 하나 밖에 없지 않았냐고요?");
		text("에이, 잘못 보셨겠죠. 기분 탓이에요.");
	}
	else {
		text("훌륭하십니다. 그럼 마왕성의 문을 열겠습니다.");
		text("");
		text("네? 자기는 선택지 중에 고르지 않았다고요?");
		text("하하, 역시 생긴 것만큼이나 농담도 잘하시네요.");
	}

	text("");
	system("cls");
	text("자, 이제 게임을 시작하겠습니다.");
	text("");
	text("아, 참고로 당신의 현재 스테이터스를 알려드리겠습니다.");
	text("");
	text("당신의 레벨은,");
	text("	1 입니다.");
	text("");
	text("당신의 체력은,");
	text("	1 입니다.");
	text("");
	text("당신의 공격력은,");
	text("	1 입니다.");
	text("");
	text("당신의 방어력은,");
	text("물어볼 것도 없이,");
	text("	1 입니다.");

	text("");
	system("cls");
	text("괜찮아요. 앞으로 더 강해지면 되니까요.");
	text("");
	text("아, 참고로,");
	text("적들의 평균 레벨은,");
	text("	999 입니다.");
	text("");
	text("제법 강한 편이죠?");
	text("");

	system("cls");

	text("그럼,");
	text("행운을 빕니다.");

	system("cls");

	int enemyCount = 0;
	int baseHP = play->hp;
	while (enemyCount < 6) {
		battle(play, enemList[enemyCount]);

		if (play -> hp <= 0)
		{
			btext("당신은 죽었습니다.");
			player.hp = baseHP;
			player.life--;

			if (play->life <= 0) {
				text("남아있는 목숨이 없습니다.");
				text("");
				text("GAME OVER");
				return;
			}
			
			btext("재도전합니다.");
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
			
			text("적을 쓰러트렸습니다");
			btext("레벨업.");
			btext("공격력 2배 업");
			btext("방어력 2배 업");
			btext("속도 2배 업");
			btext("체력 1000 업");
			text("");
			text("");
			system("cls");
			enemyCount++;
		}
	}
	
	system("cls");
	text("짝");
	text("짝");
	text("짝");
	text("");
	text("훌륭합니다.");
	text("");
	text("강력한 적들을 무찌르셨군요.");
	text("하지만, 여기서 끝이 아닙니다.");
	text("마왕은 이보다 더 강하니까요.");
	text("");
	text("기대하세요.");
	text(""); 
	text("...아마도.");
	text("");
	text("만들 시간이 된다면 말이죠.");
	text("그럼,");
	text("이만.");
	text("");
	text("To be Continued...");


}
