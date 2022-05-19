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
		string_date = "";
	}

	Date(string _date)
	{
		datetoint(_date);
		string_date = to_string(day) + "." + to_string(month) + "." + to_string(year);
	}

	void print()
	{
		string_date = to_string(day) + "." + to_string(month) + "." + to_string(year);
		cout << "Now the date is: " << string_date << endl;
	}

	void datetoint(string date) {
		do
		{
			string tempDate = "";
			for (int i = 0; i < 10; i++) {
				if (date[i] != '.') {
					tempDate += date[i];
				}


				if (i == 1) {
					day = stoi(tempDate);
					tempDate = "";
				}
				else if (i == 4) {
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
		
	}
private:
	void checkDate() {
		if (day > 31) {
			month += 1;
			day -= 31;
		}
		if (month > 12) {
			month -= 12;
			year += 1;
		}
	}
public:
	//����������
	//�������� ������������
	Date& operator=(const Date& right) {
		if (this == &right) {
			return *this;
		}
		day = right.day;
		month = right.month;
		year = right.year;
		return *this;
	}

	//�������� ��������
	Date& operator+=(const int number) {
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

	//�������� ���������
	Date& operator-=(const int number) {
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

	Date& operator+(const Date& r) {
		Date res;
		res.day = r.day + day;
		res.month = r.month + month;
		res.year = r.year + year;
		res.checkDate();
		res.string_date = to_string(res.day) + "." + to_string(res.month) + "." + to_string(res.year);
		return res;
	}

	bool operator>(const Date& right) {
		if (year > right.year) {
			return 1;
		}
		else {
			if (month > right.month) {
				return 1;
			}
			else {
				if (day > right.day) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
	bool operator<(const Date& right) {
		if (year < right.year) {
			return 1;
		}
		else {
			if (month < right.month) {
				return 1;
			}
			else {
				if (day < right.day) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
	bool operator==(const Date& right) {
		if (year == right.year && month < right.month && day < right.day) {
			return 1;
		}
		else {
			return 0;
		}
	}

};