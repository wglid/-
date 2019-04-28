#include "Qprotected.h"
#include "el.h"

void Qprotected::process()
{
	int sum = 0;
	float sr = 0;
	struct el *current = getHead();
	while (current != NULL)
	{
		sum += current->x;
		current = current->prev;
	}
	sr = (float)sum / num();
	current = getHead();
	sum = 0;
	while (current != NULL)
	{
		if (sr > current->x)
			sum++;
		current = current->prev;
	}
	cout << "Среднее значение " << sr << endl;
	cout << "Количество элементов " << sum << endl;
	system("pause");
}

void Qprotected::set(el* head)
{
	setHead(head);
}

void Qprotected::setNum(int num)
{
	countEdit(num);
}