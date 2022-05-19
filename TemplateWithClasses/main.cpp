#include <string>
#include <iostream>
#include "MediumClass.cpp"

using namespace std;


int main()
{
	string date;
	string date2 = "21.08.1669";

	//Enter date
	cout << "Entered the date string: " << endl;
	cin >> date;
	Date newDate1(date);

	//������-�� �� �������� �����
	cout << "Test the first date" << endl;
	newDate1.print();

	cout << "Test the second date" << endl;
	Date newDate2(date2);
	newDate2.print();
	
	cout << "Test the third date. Must be the same as the first one" << endl;
	Date newDate3(date);
	newDate3.print();


	//���������
	cout << "The third date must be the same as the second now." << endl;
	newDate3 = newDate2;
	newDate3.print();

	//�� �������� + � -
	cout << "Third date + 5" << endl;
	newDate3 += 5;
	newDate3.print();

	cout << "Third date - 7" << endl;
	newDate3 -= 7;
	newDate3.print();

	Date newDate4;
	cout << "Test 4" << endl;
	newDate4 = newDate3 + newDate2;
	newDate4.print();

	cout << "Compare 3rd date < 2nd date" << endl;
	if (newDate3 < newDate2) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	system("Pause");
	return 0;
}
