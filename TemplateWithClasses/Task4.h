#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Film {
protected:
	string filmName;
	string filmScenar;
	string filmCompos;
	string filmDate;
	double filmCash;
public:
	Film() {
		filmName = "Empty";
		filmScenar = "Empty";
		filmCompos = "Empty";
		filmDate = "Empty";
		filmCash = 0;
	}
	string getName();
	string getScenar();
	string getCompos();
	string getDate();
	int getCash();
	void setName(string);
	void setScenar(string);
	void setCompos(string);
	void setDate(string);
	void setCash(double);
	friend ostream& operator<<(ostream& out, const Film& r);

};


class FilmLib {
protected:
	int filmAmount;
	Film* allFilms;
public:
	FilmLib(int count) {
		filmAmount = count;
		allFilms = new Film[filmAmount];
	}
	~FilmLib() {
		delete[] allFilms;
	}
	void PrintArr();
	void FilmSortByName();
	void GetArr();
	void ReadFromFile();
};