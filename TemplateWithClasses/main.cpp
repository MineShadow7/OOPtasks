#define _CRT_SECURE_NO_WARNINGS


#include <string>
#include <iostream>
#include <fstream>

//#include "Task1.cpp"
#include "Task4.h"

using namespace std;

int main()
{

	int count;
	string path = "C:\\Users\\itmm-da\\Desktop\\Programming\\OOPtasks\\Films\\Films.txt";
	ifstream file(path);
	file >> count;
	file.close();
	FilmLib lib1(count);
	cout << "Empty arrays" << endl;
	lib1.PrintArr();
	lib1.ReadFromFile();
	cout << "Read from file arrays" << endl;
	lib1.PrintArr();
	cout << "Sort arrays" << endl;
	lib1.FilmSortByName();
	lib1.PrintArr();
	lib1.SaveToFile();
	//lib1.StartScreen();
	system("Pause");

}