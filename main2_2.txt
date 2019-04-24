#include <iostream>
#include <locale>
#include <ctime>
#include "List.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru"); 
	srand(time(NULL)); 

	bool flag = true; 
	int menu; 
	double value; 
	int size; 
	cout << "Введите размер списка: "; 
	cin >> size;

	List obj1(size); 
	List obj2(obj1); 
	while (flag) { 
		system("cls");
		cout << "1 список: "; obj1.showList();
		cout << "2 список: "; obj2.showList();
		cout << endl;
		cout << "1) Оператор +" << endl;
		cout << "2) Оператор -" << endl;
		cout << "3) Оператор *" << endl;
		cout << "4) Оператор /" << endl;
		cout << "5) Оператор ==" << endl;
		cout << "6) Оператор !=" << endl;
		cout << "0) Выход" << endl;
		cout << "Выберите пункт: ";
		cin >> menu;


		if (cin.fail() || menu < 0 || menu > 6) {
			menu = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (menu != 0 && menu != 5 && menu != 6) { 
			cout << endl;
			cout << "Введите значение: ";
			cin >> value;
		}
		switch (menu) {
		case 1: obj2 = obj1 + value; break; 
		case 2: obj2 = obj1 - value; break; 
		case 3: obj2 = obj1 * value; break; 
		case 4: obj2 = obj1 / value; break;
		case 5: 
			if (obj1 == obj2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
			system("pause");
			break;
		case 6:
			if (obj1 != obj2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
			system("pause");
			break;
		case 0: flag = false;
		}
	}
}