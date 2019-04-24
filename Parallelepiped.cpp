#include "Parallelepiped.h"
#include <iostream>
#include <fstream>

using namespace std;

Parallelepiped::Parallelepiped() {
	ifstream fin("Parallelepiped.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "������! ���� Parallelepiped.txt �� �������� ��� ������!" << endl;
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
		cout << "������! ���� Parallelepiped.txt �� �������� ��� ������!" << endl;
		system("pause");
		exit(1);
	}
	fout << A << " " << B << " " << C;
	fout.close();
}

void Parallelepiped::surfaceArea() {
	system("cls");
	cout << "��������������" << endl << endl;
	cout << "������� A: " << A << endl;
	cout << "������� B: " << B << endl;
	cout << "������� C: " << C << endl;
	cout << endl << "������� ����������� ��������������� �����: " << 2 * (A * B + B * C + A * C) << endl << endl;
	system("pause");
}

void Parallelepiped::changeData() {
	cout << endl << "������� ����� ������:" << endl;
	cout << "����� ������� �: ";
	cin >> this->A;
	cout << "����� ������� B: ";
	cin >> this->B;
	cout << "����� ������� C: ";
	cin >> this->C;
	cout << endl << "������ ��������" << endl << endl;
	system("pause");
}
