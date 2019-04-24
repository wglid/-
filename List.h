#pragma once
#include "Node.h"


class List {
	Node *head;
	Node *tail;
	int size;
public:
	List() : head(nullptr), tail(nullptr), size(0) {}; 
	List(int count); 
	List(const List& other); 
	~List();
	void pushNode(double value); 
	void showList(); 

	
	List& operator = (const List& obj);
	List operator + (double value);
	List operator - (double value);
	bool operator == (const List& obj);

	
	friend bool operator != (List& obj1, const List& obj2);
	friend List operator * (const List& obj, double value);
	friend List operator / (const List& obj, double value);


};