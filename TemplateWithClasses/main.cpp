#define _CRT_SECURE_NO_WARNINGS


#include <string>
#include <iostream>
#include "Task3.h"

using namespace std;

int main()
{
	//Task 3
	MyTextEditor obj1;
	setlocale(LC_ALL, "Russian");
	cout << obj1;
	cin >> obj1;

	obj1.PrintLenText();
	obj1.HavaAChoiceThenWork();
}