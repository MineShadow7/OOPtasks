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
	string path = "C:\\Users\\itmm-da\\Desktop\\Programming\\OOPtasks\\Films\\Films.txt";
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
	void ReadFromFile();
	//void StartScreen();
	void CreateFilm();
	void EditFilmbyName();
	void FindFilmbyNameandDate();
	void FindFilmbyDate();
	void FindFilmbyCash();
	void FindFilmbyCashinYear();
	void PrintAmount();
	void DeleteFilm(int index);
	void SaveToFile();

	FilmLib operator=(const FilmLib& r) {
		if (this == &r) {
			return *this;
		}
		for (int i = 0; i < filmAmount; i++) {
			//тут все поля которые мы запишем в файл.
		}
	}
};