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
	int filmCash;
public:

};
class FilmLib {
protected:
	int filmAmount;
	Film* allFilms;
public:
	FilmLib(int count) {
		filmAmount = count;
		filmName = new string[filmAmount];
		filmScenar = new string[filmAmount];
		filmCompos = new string[filmAmount];
		filmDate = new string[filmAmount];
		filmCash = new int[filmAmount];
		for (int i = 0; i < filmAmount; i++) {
			filmName[i] = "blank";
			filmScenar[i] = "blank";
			filmCompos[i] = "blank";
			filmDate[i] = "blank";
			filmCash[i] = 0;
		}
	}
	~FilmLib() {
		delete[] filmName;
		delete[] filmScenar;
		delete[] filmCompos;
		delete[] filmDate;
		delete[] filmCash;
	}
	void PrintArr();
	void FilmSort();
	void GetArr();
	void ReadFromFile();
};