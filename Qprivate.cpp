#include "Qprivate.h"
#include "el.h"

void Qprivate::process()
{
	int sum = 0;
	float sr = 0;
	struct el *current = getHead();
	while (current != NULL) //�� ������� � ����� � ������ (����� ���� ��������� � �������)
	{
		sum += current->x;
		current = current->prev;
	}
	sr = (float)sum / num();
	current = getHead(); //�������� � ����� �������
	sum = 0;
	while (current != NULL) //������� ���-�� ��������� ������ �������� ��������
	{
		if (sr > current->x)
			sum++;
		current = current->prev;
	}
	cout << "������� �������� " << sr << endl;
	cout << "���������� ��������� " << sum << endl;
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
