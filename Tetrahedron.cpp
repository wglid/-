#include "Tetrahedron.h"
#include <iostream>
#include <fstream>

using namespace std;

Tetrahedron::Tetrahedron() {
	ifstream fin("Tetrahedron.txt", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "Ошибка! Файл Tetrahedron.txt не открылся для чтения!" << endl;
		system("pause");
		exit(1);
	}
	fin >> A;
	fin.close();
}

Tetrahedron::~Tetrahedron() {
	ofstream fout("Tetrahedron.txt", ios::out | ios::binary);
	if (!fout.is_open())
	{
		cout << "Ошибка! Файл Tetrahedron.txt не открылся для записи!" << endl;
		system("pause");
		exit(1);
	}

	fout << A;
	fout.close();
}

void Tetrahedron::surfaceArea() {
	system("cls");
	cout << "Тетраэдр" << endl << endl;
	cout << "Сторона: " << A << endl;
	cout << endl << "Плошадь поверхности тетраэдра равна: " << 1.73 * A * A << endl << endl;
	system("pause");
}

void Tetrahedron::changeData() {
	cout << endl << "Введите новые данные:" << endl;
	cout << "Новая сторона тетраэдра: ";
	cin >> this->A;
	cout << endl << "Данные изменены" << endl << endl;
	system("pause");
}
