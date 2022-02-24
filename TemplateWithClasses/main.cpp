#include <string>
#include <iostream>
#include "MediumClass.cpp"

using namespace std;


int main()
{
	int day = 0;
	int month = 0;
	int year = 0;

	int day2 = 18;
	int month2 = 7;
	int year2 = 1653;
	string date ;

	//Enter date



	cout << "Entered the date string: " << endl;


	do
	{
		string tempDate = "";
		cin >> date;


		for (int i = 0; i < 10; i++) {
			if (date[i] != '.') {
				tempDate += date[i];
			}


			if (i == 1) {
				day = stoi(tempDate);
				tempDate = "";
			} else if (i == 4) {
				month = stoi(tempDate);
				tempDate = "";
			}
			else if (i == 9) {
				year = stoi(tempDate);
				tempDate = "";
			}
		}



		if ((day > 31) || (day < 1) || (month > 12) || (month < 1) || (year < 0))
			cout << "The date you typed contains errors. Check if such date can exist and type again: ";
		
	} while ((day > 31) || (day < 1) || (month > 12) || (month < 1) || (year < 0));




	Date newDate1(day, month, year);

	//почему-то не работает вывод
	newDate1.print();

	Date newDate2(day2, month2, year2);
	newDate2.print();
	
	Date newDate3(day2, month2, year2);
	newDate3.print();


	//Операторы
	newDate3 = newDate2;
	newDate3.print();

	//Не работают + и -
	newDate3 + 5;
	newDate3.print();

	newDate3 - 5;
	newDate3.print();

	newDate3 >> newDate2;



	return 0;
}
