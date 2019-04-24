#include "Sphere.h"
#include <iostream>
#include <fstream>

using namespace std;

Sphere::Sphere() {
	ifstream fin("Sphere.txt", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "������! ���� Sphere.txt �� �������� ��� ������!" << endl;
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
		cout << "������! ���� Sphere.txt �� �������� ��� ������!" << endl;
		system("pause");
		exit(1);
	}

	fout << R;
	fout.close();
}

void Sphere::surfaceArea() {
	system("cls");
	cout << "���" << endl << endl;
	cout << "������: " << R << endl;
	cout << endl << "������� ����������� ���� �����: " << 4 * 3.14 * R * R << endl << endl;
	system("pause");
}

void Sphere::changeData() {
	cout << endl << "������� ����� ������:" << endl;
	cout << "����� ������ ����: ";
	cin >> this->R;
	cout << endl << "������ ��������" << endl << endl;
	system("pause");
}
