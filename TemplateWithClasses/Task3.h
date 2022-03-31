//Copyright 2022 Andrew Karagodin
#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;
#define KEY_EXIT 27
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75

class MyTextEditor{
protected:
COORD cursorPos;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD cWrittenChars;
int len;
int baselen;
bool selectedChoice;
char* Characters;
 public:
MyTextEditor(){
len = 1;
baselen = len;
selectedChoice = 0;
cursorPos.X = 0;
cursorPos.Y = 0;
SetConsoleCursorPosition(hStdOut, cursorPos);
};
void printValues() {
cout << "X: " << cursorPos.X << endl << "Y: " << cursorPos.Y << endl << "len: " << len << endl;
}
void HavaAChoiceThenWork() {
char ch = ' ';
if (selectedChoice == 1) {
cout << "Хотите продолжить редактирование текста?" << endl;
cout << "Enter = Да" << endl << "Esc = Нет" << endl;
ch = _getche();
if (ch == KEY_EXIT) {
system("pause");
}
else {
	if (ch == '\r') {
	PrintLenText();
	WorkWithText();
  }
 }
}
else {
ch = '\n';
}
if (ch == '\n') {
PrintLenText();
WorkWithText();
 }
}
void PrintLenText() {
system("CLS");
SetConsoleCursorPosition(hStdOut, cursorPos);
FillConsoleOutputCharacter(hStdOut, (TCHAR)'_', len, cursorPos, &cWrittenChars);
SetConsoleCursorPosition(hStdOut, cursorPos);
}
void WorkWithText() {
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int zagl = 67;  //Заглушка как учили.
baselen = len;
CONSOLE_SCREEN_BUFFER_INFO cbsi;
while (zagl != KEY_EXIT && len > 0) {
switch (zagl) {
case KEY_ARROW_LEFT:
GetConsoleScreenBufferInfo(hStdOut, &cbsi);
cursorPos.X = cbsi.dwCursorPosition.X - 1;
SetConsoleCursorPosition(hStdOut, cursorPos);
len++;
zagl = 67;
break;
case KEY_ARROW_RIGHT:
GetConsoleScreenBufferInfo(hStdOut, &cbsi);
cursorPos.X = cbsi.dwCursorPosition.X + 1;
SetConsoleCursorPosition(hStdOut, cursorPos);
len--;
zagl = 67;
break;
default:
zagl = _getch();
if (zagl == KEY_EXIT || zagl == ARROW_KEY || zagl == KEY_SPACE
|| zagl == KEY_ARROW_LEFT || zagl == KEY_ARROW_RIGHT) break;
std::cout << (char)zagl;
len--;
break;
 }
}
Characters = new char[baselen + 1];
DWORD dwRead;
ReadConsoleOutputCharacter(hStdOut, Characters, baselen, cursorPos, &dwRead);
Characters[baselen] = '\0';
system("CLS");
cout << "Your final text: " << Characters << endl;
len = baselen;
system("pause");
system("CLS");
selectedChoice = 1;
HavaAChoiceThenWork();
}

friend ostream& operator<<(ostream& out, const MyTextEditor& r);
friend istream& operator>>(istream& in, MyTextEditor& r);

};

istream& operator>>(istream& in, MyTextEditor& right) {
cout << "Отступ сверху (Y): ";
in >> right.cursorPos.Y;
cout << "Отступ слева (X): ";
in >> right.cursorPos.X;
cout << "Длина текста (len): ";
in >> right.len;
right.printValues();
return in;
}

ostream& operator<<(ostream& out, const MyTextEditor& r) {
out << "Введите значения для отступа слева (x), сверху (y), а также длину текста(len)" << endl;
return out;
}
