#include "Sphere.h"
#include <iostream>
#include <fstream>

using namespace std;

Sphere::Sphere() {
	ifstream fin("Sphere.txt", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "Ошибка! Файл Sphere.txt не открылся для чтения!" << endl;
		system("pause");
		exit(1);
	}
	fin >> R;
	fin.close();
}

Sphere::~Sphere() {
	ofstream fout("Sphere.txt", ios::out | ios::binary);
	if (!fout.is_open())
	{
		cout << "Ошибка! Файл Sphere.txt не открылся для записи!" << endl;
		system("pause");
		exit(1);
	}

	fout << R;
	fout.close();
}

void Sphere::surfaceArea() {
	system("cls");
	cout << "Шар" << endl << endl;
	cout << "Радиус: " << R << endl;
	cout << endl << "Плошадь поверхности шара равна: " << 4 * 3.14 * R * R << endl << endl;
	system("pause");
}

void Sphere::changeData() {
	cout << endl << "Введите новые данные:" << endl;
	cout << "Новый радиус шара: ";
	cin >> this->R;
	cout << endl << "Данные изменены" << endl << endl;
	system("pause");
}
