#include "Parallelepiped.h"
#include <iostream>
#include <fstream>

using namespace std;

Parallelepiped::Parallelepiped() {
	ifstream fin("Parallelepiped.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "Ошибка! Файл Parallelepiped.txt не открылся для чтения!" << endl;
		system("pause");
		exit(1);
	}
	fin >> A >> B >> C;
	fin.close();
}

Parallelepiped::~Parallelepiped() {
	ofstream fout("Parallelepiped.txt", ios::out | ios::binary);
	if (!fout.is_open())
	{
		cout << "Ошибка! Файл Parallelepiped.txt не открылся для записи!" << endl;
		system("pause");
		exit(1);
	}
	fout << A << " " << B << " " << C;
	fout.close();
}

void Parallelepiped::surfaceArea() {
	system("cls");
	cout << "Параллелепипед" << endl << endl;
	cout << "Сторона A: " << A << endl;
	cout << "Сторона B: " << B << endl;
	cout << "Сторона C: " << C << endl;
	cout << endl << "Плошадь поверхности параллелепипеда равна: " << 2 * (A * B + B * C + A * C) << endl << endl;
	system("pause");
}

void Parallelepiped::changeData() {
	cout << endl << "Введите новые данные:" << endl;
	cout << "Новая сторона А: ";
	cin >> this->A;
	cout << "Новая сторона B: ";
	cin >> this->B;
	cout << "Новая сторона C: ";
	cin >> this->C;
	cout << endl << "Данные изменены" << endl << endl;
	system("pause");
}
