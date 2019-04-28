#include "Qprivate.h"
#include "el.h"

void Qprivate::process()
{
	int sum = 0;
	float sr = 0;
	struct el *current = getHead();
	while (current != NULL) //по очереди с конца в начало (сумма всех элементов в очереди)
	{
		sum += current->x;
		current = current->prev;
	}
	sr = (float)sum / num();
	current = getHead(); //начинаем с конца очереди
	sum = 0;
	while (current != NULL) //считаем кол-во элементов меньше среднего значения
	{
		if (sr > current->x)
			sum++;
		current = current->prev;
	}
	cout << "Среднее значение " << sr << endl;
	cout << "Количество элементов " << sum << endl;
	system("pause");
}

void Qprivate::set(el* head) 
{
	setHead(head);
}

void Qprivate::setNum(int num)
{
	countEdit(num);
}
