#include <iostream>
#include <locale>
#include "Dimensions.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int height;
	int width;
	int depth;

	cout << "Введите высоту: ";
	cin >> height;
	cout << "Введите ширину: ";
	cin >> width;
	cout << "Введите глубину: ";
	cin >> depth;

	Dimensions obj(height, width, depth);
	int menu;
	bool flag = true;

	while (flag)
	{
		system("cls");
		obj.show();
		cout << "1) ++obj" << endl;
		cout << "2) obj++" << endl;
		cout << "3) --obj" << endl;
		cout << "4) obj--" << endl;
		cout << "0) Выход" << endl;
		cout << "Выберите команду: ";
		cin >> menu;
		if (cin.fail()) {
			menu = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (menu)
		{
		case 1:	++obj; break;
		case 2: obj++; break;
		case 3: --obj; break;
		case 4: obj--; break;
		case 0: flag = false;
		}
	}
}