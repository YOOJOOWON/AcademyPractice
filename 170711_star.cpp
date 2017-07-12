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




	//추가
	//이중 for문 없이
	//과제 1
	cout << "과제1" << endl;
	int j = 0;
	bool line = true;
	for (int i = 0; i < 25; i++) {
		if (line)
		{
			j = (i / 5) + 1;
			line = false;
		}
		if (j > 0)
		{
			cout << "*";
			j--;
		}
		else
		{
			cout << " ";
		}
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
			line = true;
		}
	}
	//과제 2
	cout << "과제2" << endl;
	j = 0;
	line = true;
	for (int i = 24; i >= 0; i--) {
		if (line)
		{
			j = (i / 5) + 1;
			line = false;
		}
		if (j > 0)
		{
			cout << "*";
			j--;
		}
		else
		{
			cout << " ";
		}
		if ((i) % 5 == 0)
		{
			cout << endl;
			line = true;
		}
	}
	//과제 3
	cout << "과제3" << endl;
	j = 0;
	line = true;
	for (int i = 24; i >= 0; i--) {
		if (line)
		{
			j = (i / 5);
			line = false;
		}
		if (j > 0)
		{
			cout << " ";
			j--;
		}
		else
		{
			cout << "*";
		}
		if ((i) % 5 == 0)
		{
			cout << endl;
			line = true;
		}
	}
	//과제 4
	cout << "과제4" << endl;
	j = 0;
	line = true;
	for (int i = 0; i < 25; i++) {
		if (line)
		{
			j = (i / 5);
			line = false;
		}
		if (j > 0)
		{
			cout << " ";
			j--;
		}
		else
		{
			cout << "*";
		}
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
			line = true;
		}
	}


	//정답
	char* star = "*****";
	char* space = "     ";

	for (int i = 0; i < 5; i++) {
		cout << star + i << endl;
	}
}

