#define _CRT_SECURE_NO_WARNINGS


#include <string>
#include <iostream>

//#include "Task1.cpp"
#include "Task2.h"
#include "Task3.h"

using namespace std;

int main()
{
	//Task2
	/*
	int size, size2;
	char arraynumber;
	*/
	/*
	cout << "Enter size of the number: ";
	cin >> size; 

	Octonumb octoNumber1(size);
	cin >> octoNumber1;

	octoNumber1.numberToChar(octoNumber1.getNumber());
	cout << octoNumber1;

	cout << "Enter size of the number 2: ";
	cin >> size2;
	Octonumb octoNumber2(size2);
	cin >> octoNumber2;

	octoNumber2.numberToChar(octoNumber2.getNumber());
	cout << octoNumber2;

	//octoNumber1 = octoNumber2;
	//cout << octoNumber1;

	/*
	octoNumber1 + 3;
	cout << octoNumber1;

	octoNumber1 - 3;
	cout << octoNumber1;
	*/
	/*
	if (octoNumber1 == octoNumber2)
		cout << "Same!" << endl;
	else
		cout << "Different!" << endl;

	if (octoNumber1 < octoNumber2)
		cout << "Smaller!" << endl;
	else
		cout << "Not smaller!" << endl;

	if (octoNumber1 > octoNumber2)
		cout << "Bigger!" << endl;
	else
		cout << "Not bigger!" << endl;

	arraynumber = octoNumber1[2];
	cout << arraynumber << endl;
	*/

	//Task 3
	setlocale(LC_ALL, "Russian");
	MyTextEditor obj1;
	cout << obj1;
	cin >> obj1;

	obj1.PrintLenText();
	obj1.HavaAChoiceThenWork();


	
	
	
}