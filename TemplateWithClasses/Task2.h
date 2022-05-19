#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Octonumb {
protected:
	int size;
	int number;
	char *numstr;
	char* realnum;
	string tmp;

public:
	//����������� �������������
	Octonumb() {
		size = 0;
		number = 0;
	}
	Octonumb(int _size) {
		size = _size;
	}
	~Octonumb() {
		delete[] numstr;
		delete[] realnum;
	}
	int getSize() {
		return size;
	}
	string getNumber() {
		return tmp;
	}
	void numberToChar(string tmp) {
		numstr = new char[size];
		realnum = new char[size];
		int flag = 0;
		for (int i = 0; i < size; i++) {
			if (tmp[i] > '7') {
				flag = 1;
			}
		}
		if (flag != 1) {
			strcpy(numstr, tmp.c_str());
			realnum = numstr;
		}
		else {
			cout << "Input number outside of range! Rebuilding the number...";
			numberRebuild(tmp);
		}
		
	}
	void numberRebuild(string oldtmp) {
		string test;
		if (oldtmp[0] == '8') {
			size += 1;
			test = new char[size];
			test[0] = '0';
			for (int i = 0; i < oldtmp.length(); i++) {
				test[i + 1] = oldtmp[i];
			}
		}
		if (oldtmp[0] != '8') {
			test = new char[size];
			for (int i = 0; i < oldtmp.length(); i++) {
				test[i] = oldtmp[i];
			}
		}
		for (int j = 0; j < size; j++) {
			if (test[j] > '7') {
				test[j - 1] += 1;
				test[j] -= 7;
			}
		}
		for (int k = 0; k < size; k++) {
			numstr[k] = test[k];
			realnum[k] = numstr[k];
			cout << numstr[k];
		}
		cout << endl;
		numberToChar(numstr);
	}
	Octonumb& operator=(const Octonumb& right) {
		if (this == &right) {
			return *this;
		}
		size = right.size;
		numberToChar(right.numstr);
	}
	Octonumb& operator+=(int _number) {
		number = atoi(numstr);
		number += _number;
		tmp = to_string(number);
		numberToChar(tmp);
		return *this;
	}
	Octonumb& operator-=(int _number) {
		Octonumb res;
		number = atoi(numstr);
		res.number = number - _number;
		res.tmp = new char[size];
		res.tmp = to_string(res.number);
		numberToChar(res.tmp);
		return res;
	}
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
	friend ostream& operator<<(ostream& out, const Octonumb& r);
	friend istream& operator>>(istream& in, Octonumb& r);
};

istream& operator>>(istream& in, Octonumb& right) {
	cout << "Input number: ";
	in >> right.tmp;
	return in;
}

ostream& operator<<(ostream& out, const Octonumb& r) {

	out << "your number is: ";
	for (int i = 0; i < r.size; i++) {
		out << r.realnum[i];
	}
	out << endl;
	return out;
}


