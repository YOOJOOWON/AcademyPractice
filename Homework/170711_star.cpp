#include<iostream>
#include<time.h>
using namespace std;
//한 변수의 집합 -> 배열
//여러 변수의 집합 -> 구조체

void main(void) {

	//과제1
	//*****
	//****
	//***
	//**
	//*
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << endl;
	}

	//과제2
	//    *
	//   **
	//  ***
	// ****
	//*****
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4-i; j++)
			cout << " ";
		for (int k = 0; k < i+1; k++)
			cout << "*";
		cout << endl;
	}

	//과제3
	//*****
	// ****
	//  ***
	//   **
	//    *

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int k = 0; k < 5 - i; k++)
			cout << "*";
		cout << endl;
	}

}