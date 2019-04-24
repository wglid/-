#include "Tetrahedron.h"
#include <iostream>
#include <fstream>

using namespace std;

Tetrahedron::Tetrahedron() {
	ifstream fin("Tetrahedron.txt", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cout << "������! ���� Tetrahedron.txt �� �������� ��� ������!" << endl;
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
		cout << "������! ���� Tetrahedron.txt �� �������� ��� ������!" << endl;
		system("pause");
		exit(1);
	}

	fout << A;
	fout.close();
}

void Tetrahedron::surfaceArea() {
	system("cls");
	cout << "��������" << endl << endl;
	cout << "�������: " << A << endl;
	cout << endl << "������� ����������� ��������� �����: " << 1.73 * A * A << endl << endl;
	system("pause");
}

void Tetrahedron::changeData() {
	cout << endl << "������� ����� ������:" << endl;
	cout << "����� ������� ���������: ";
	cin >> this->A;
	cout << endl << "������ ��������" << endl << endl;
	system("pause");
}
