#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class och
{
	struct el *head; // ������ �������
	int count;
public:
	och(){ head = NULL; count = 0;};
	int num(); // ���������� count
	void show();
	void put(); // ���������� ������ ��������
	void cut();
	void copy(och *copy); // copy - ���� ����������� �������
	void sub(och *first, och *second); // ������� ������� firsh � second
	void countEdit(int num); // �������� ���������� ���������
	struct el* getHead(); // ��������� ������
	struct el* setHead(struct el* newHead); // ���������� ������
};

#include <J:/��������/Qpublic.h>
#include <J:/��������/Qprivate.h>
#include <J:/��������/Qprotected.h>
