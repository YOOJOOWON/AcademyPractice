#include<iostream>
#include<time.h>
using namespace std;
//한 변수의 집합 -> 배열
//여러 변수의 집합 -> 구조체

struct Skill {
	int baseDamage;
};

struct Pokemon
{
	int Lv;
	int HP;
	Skill skList[];
	
};

void main(void) {
	Pokemon pikachu;
	pikachu.HP = 200;
	
	//포인터
	int a = 7;
	int b = 6;
	int* c;
	cout << "b의 값은 : " << b << endl;
	c = &b;
	cout << "&b의 값은 : " << &b << endl;
	*c = 7;
	cout << "b의 값은 : " << b << endl;


	//과제
	//*****
	//****
	//***
	//**
	//*

	//    *
	//   **
	//  ***
	// ****
	//*****

	//*****
	// ****
	//  ***
	//   **
	//    *

}