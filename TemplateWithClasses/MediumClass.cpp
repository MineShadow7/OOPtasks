#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
	int day;
	int month;
	int year;

	std::string string_date;


	Date() {
		day = 0;
		month = 0;
		year = 0;
	}

	Date(int _day, int _month, int _year)
	{
		day = _day;
		month = _month;
		year = _year;
		string_date = to_string(_day) + "." + to_string(_month) + "." + to_string(_year);
	}

	void print()
	{
		cout << "Now the date is: " << string_date << endl;
	}


	//Перегрузка
	//Оператор присваивания
	Date& operator=(const Date& right) {
		if (this == &right) {
			return *this;
		}
		day = right.day;
		month = right.day;
		year = right.year;
		return *this;
	}

	//Оператор сложения
	Date& operator+(const int number) {
		day += number;
		if (day > 31) {
			month += 1;
			day = day - 31;
		}
		if (month > 12) {
			year += 1;
			month = month - 12;
		}
		return *this;
	}

	//Оператор вычитания
	Date& operator-(const int number) {
		day -= number;
		if (day < 1) {
			day = 1;
		}
		if (month < 1) {
			month = 1;
		}
		if (year < 1) {
			year = 1;
		}
		return *this;
	}

	//Оператор сравнения
	Date& operator>>(const Date& right) {

		if (year < right.year) {
			cout << "Right date is bigger" << endl;
		else {
			if (month < right.month) {
				cout << "Right date is bigger" << endl;
			}
			else {
				if (day < right.day) {
					cout << "Right date is bigger" << endl;
				}
				else {
					cout << "Left date is bigger" << endl;
				}
					if (day == right.day && month == right.month && year == right.year) {
						cout << "These are the same dates!" << endl;
					}
				}
			}
		}
		return *this;
	}
	

};

