#include <iostream>
#include "Square.h"

using namespace std;

void menuFigure(Square *ptr) {
	int figure;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "1) �������� ���������� � ������" << endl;
		cout << "2) �������� ������ � ������" << endl;
		cout << "0) ����� � �������� ����" << endl;
		cout << "�������� �������: ";
		cin >> figure;
		if (cin.fail()) {
			figure = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (figure)
		{
		case 1: ptr->surfaceArea(); break;
		case 2: ptr->changeData(); break;
		case 0: flag = false;
		}
	}
}