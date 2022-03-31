#define _CRT_SECURE_NO_WARNINGS

#pragma once


#include <iostream>
#include <string>



using namespace std;

class Octonumb {
protected:
	int size;
	int number;
	char *numstr;
	string tmp;

public:
	//Конструктор инициализации

	Octonumb() {
		size = 0;
		number = 0;

	}

	Octonumb(int _size) {
		size = _size;
	}


	~Octonumb() {
		delete[] numstr;
	}

	int getSize() {
		return size;
	}

	string getNumber() {
		return tmp;
	}

	void numberToChar(string tmp) {
		int flag = 0;
		numstr = new char[tmp.length() + 1];
		for (int i = 0; i < size; i++) {
			if (tmp[i] > '7') {
				cout << "Input wrong number. Try again!";
				flag = 1;
			}
		}
		if (flag != 1)
			strcpy(numstr, tmp.c_str());
		else {
			system("Pause");
			exit(1);
		}
		
	}

	friend ostream& operator<<(ostream& out, const Octonumb& r);
	friend istream& operator>>(istream& in, Octonumb& r);

	Octonumb& operator=(const Octonumb& right) {
		if (this == &right) {
			return *this;
		}
		size = right.size;
		numberToChar(right.tmp);
	}
	/*
	Octonumb& operator+(const Octonumb& right) {
		Octonumb res;
		number = atoi(numstr);
		res.number = number + right.size;
		res.tmp = new char[size];
		res.tmp = to_string(res.number);
		numberToChar(res.tmp);
		return res;
	}

	Octonumb& operator+(const Octonumb& right) {
		Octonumb res;
		number = atoi(numstr);
		res.number = number - right.size;
		res.tmp = new char[size];
		res.tmp = to_string(res.number);
		numberToChar(res.tmp);
		return res;
	}
	*/

	bool operator==(const Octonumb& right) {
		if (size != right.size)
			return 0;
		else {
			const char* rightchar = right.numstr;
			const char* leftchar = numstr;
			if (strcmp(leftchar, rightchar) == 0)
				return 1;
			else
				return 0;
		}

	}


	bool operator<(const Octonumb& right) {
		if (size < right.size)
			return 1;
		else {
			const char* rightchar = right.numstr;
			const char* leftchar = numstr;
			if (strcmp(leftchar, rightchar) == -1)
				return 1;
			else
				return 0;
		}
	}

	bool operator>(const Octonumb& right) {
		if (size > right.size)
			return 1;
		else {
			const char* rightchar = right.numstr;
			const char* leftchar = numstr;
			if (strcmp(leftchar, rightchar) == 1)
				return 1;
			else
				return 0;
		}
	}

	char operator[](int index) {
		if (index > size) {
			cout << "Invalid index of the number. Index is bigger than max size";
			return 0;
		}
		else {
			if (index < 0) {
				cout << "Invalid index of the number. Index is smaller than minimal size";
				return 0;
			}
			else
			{
				return numstr[index];
			}
		}

	}
};



istream& operator>>(istream& in, Octonumb& right) {
	cout << "Input number: ";
	in >> right.tmp;
	return in;
}

ostream& operator<<(ostream& out, const Octonumb& r) {

	out << "your number is: " << r.numstr << endl;
	return out;
}


