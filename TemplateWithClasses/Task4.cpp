#include "Task4.h"

void FilmLib::PrintArr() {
	for (int i = 0; i < filmAmount; i++) {
		cout << filmName[i] << endl << filmScenar[i] << endl << filmCompos[i] << endl << filmDate[i] << endl << filmCash[i] << endl << endl;
	}
}
void FilmLib::FilmSort() {
	string n, s, cm, d;
	double c;
	for (int i = 0; i < filmAmount-1; i++) {
		for (int j = i; j >= 0; j--) {
			if (filmName[j] > filmName[j + 1]) {
				n = filmName[j];
				s = filmScenar[j];
				cm = filmCompos[j];
				d = filmDate[j];
				c = filmCash[j];
				filmName[j] = filmName[j + 1];
				filmScenar[j] = filmScenar[j + 1];
				filmCompos[j] = filmCompos[j + 1];
				filmDate[j] = filmDate[j + 1];
				filmCash[j] = filmCash[j + 1];
				filmName[j + 1] = n;
				filmScenar[j + 1] = s;
				filmCompos[j + 1] = cm;
				filmDate[j + 1] = d;
				filmCash[j + 1] = c;
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
		filmName[i] = buf;
		cout << endl;

		cout << "Scenarist=> ";
		cin.getline(buf, 80, '\n');
		filmScenar[i] = buf;
		cout << endl;

		cout << "Composer=> ";
		cin.getline(buf, 80, '\n');
		filmCompos[i] = buf;
		cout << endl;

		cout << "Date=> ";
		cin.getline(buf, 80, '\n');
		filmDate[i] = buf;
		cout << endl;

		filmCash[i] = 0;
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
					filmName[i] = s;
				}
				if (index == 2) {
					filmScenar[i] = s;
				}
				if (index == 3) {
					filmCompos[i] = s;
				}
				if (index == 4) {
					filmDate[i] = s;
				}
				if (index == 5) {
					filmCash[i] = atoi(s.c_str());
					index = 0;
					i++;
				}
			}
			index++;
		}
	}
	file.close();
}