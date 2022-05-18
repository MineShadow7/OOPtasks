#include "Task4.h"


ostream& operator<<(ostream& out, const Film& r) {
	out << "Film:" << endl << r.filmName << endl << r.filmScenar << endl << r.filmCompos << endl << r.filmDate << endl << r.filmCash << endl;
	return out; 
}

string Film::getName() {
	return filmName;
}
string Film::getScenar() {
	return filmScenar;
}
string Film::getCompos() {
	return filmCompos;
}
string Film::getDate() {
	return filmDate;
}
int Film::getCash() {
	return filmCash;
}

void Film::setName(string _new) {
	filmName = _new;
}
void Film::setScenar(string _new) {
	filmScenar = _new;
}
void Film::setCompos(string _new) {
	filmCompos = _new;
}
void Film::setDate(string _new) {
	filmDate = _new;
}
void Film::setCash(double _new) {
	filmCash = _new;
}

void FilmLib::PrintArr() {
	for (int i = 0; i < filmAmount; i++) {
		cout << allFilms[i] << endl;
	}
}
void FilmLib::FilmSortByName() {
	string n, s, cm, d;
	double c;
	for (int i = 0; i < filmAmount-1; i++) {
		for (int j = i; j >= 0; j--) {
			if (allFilms[j].getName() > allFilms[j + 1].getName()) {
				n = allFilms[j].getName();
				s = allFilms[j].getScenar();
				cm = allFilms[j].getCompos();
				d = allFilms[j].getDate();
				c = allFilms[j].getCash();
				allFilms[j].setName(allFilms[j+1].getName());
				allFilms[j].setScenar(allFilms[j + 1].getScenar());
				allFilms[j].setCompos(allFilms[j + 1].getCompos());
				allFilms[j].setDate(allFilms[j + 1].getDate());
				allFilms[j].setCash(allFilms[j + 1].getCash());
				allFilms[j + 1].setName(n);
				allFilms[j + 1].setScenar(s);
				allFilms[j + 1].setCompos(cm);
				allFilms[j + 1].setDate(d);
				allFilms[j + 1].setCash(c);
			}
		}
	}
}
void FilmLib::GetArr() {
	char buf[80];
	double cash;
	cin.ignore(4096, '\n');
	for (int i = 0; i < filmAmount; i++) {
		cout << "Name=> ";

		cin.getline(buf, 80, '\n');
		allFilms[i].setName(buf);
		cout << endl;

		cout << "Scenarist=> ";
		cin.getline(buf, 80, '\n');
		allFilms[i].setScenar(buf);
		cout << endl;

		cout << "Composer=> ";
		cin.getline(buf, 80, '\n');
		allFilms[i].setCompos(buf);
		cout << endl;

		cout << "Date=> ";
		cin.getline(buf, 80, '\n');
		allFilms[i].setDate(buf);
		cout << endl;

		allFilms[i].setCash(0);
	}
}
void FilmLib::ReadFromFile() {
	ifstream file("C:\\Users\\shad-\\Documents\\Programming\\OOPtasks\\Films\\Films.txt");
	string s;
	int index = 0;
	int i = 0;
	while (getline(file, s)) {
		if (s != "") {
			if (index != 0 && i != filmAmount) {
				if (index == 1) {
					allFilms[i].setName(s);
				}
				if (index == 2) {
					allFilms[i].setScenar(s);
				}
				if (index == 3) {
					allFilms[i].setCompos(s);
				}
				if (index == 4) {
					allFilms[i].setDate(s);
				}
				if (index == 5) {
					allFilms[i].setCash(atoi(s.c_str()));
					index = 0;
					i++;
				}
			}
			index++;
		}
	}
	file.close();
}