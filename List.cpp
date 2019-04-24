#include <iostream>
#include "List.h"

using namespace std;

List::List(int count){
	int value; 
	for (int i = 0; i < count; ++i) { 
		value = rand() % 101; 
		pushNode(value);
	}
}

List::List(const List & other) { 
	head = tail = nullptr;
	size = 0;
	Node *tmp = other.head; 
	for(int i = 0; i < other.size; ++i) {  
		pushNode(tmp->data); 
		tmp = tmp->pNext; 
	}
}

List::~List() {
	while (size != 0) 
	{
		Node *temp = head->pNext;
		delete head; 
		head = temp; 
		size--; 
	}
}

void List::pushNode(double value) {
	size++; 

	Node  *temp = new Node; 
	temp->pNext = head; 
	temp->data = value; 

	if (head != nullptr) 
	{
		tail->pNext = temp; 
		tail = temp; 
	}
	else head = tail = temp; 
}

void List::showList() {
	Node *tempHead = head; 

	int temp = size; 
	while (temp != 0) 
	{
		cout << tempHead->data << " "; 
		tempHead = tempHead->pNext;
		temp--; 
	}
	cout << endl;
}

List& List::operator=(const List & obj) {

	Node *tmpObj = obj.head;
 	Node *tmpThis = this->head; 
	for (int i = 0; i < obj.size; ++i) { 
		tmpThis->data = tmpObj->data; 
		tmpThis = tmpThis->pNext; 
		tmpObj = tmpObj->pNext;
	}
	return *this;


List List::operator+(double value)
{
	List res; 
	Node *tmp = this->head; 
	for (int i = 0; i < this->size; ++i) {
		res.pushNode(tmp->data + value); 
		tmp = tmp->pNext; 
	}
	return res; 
}

List List::operator-(double value)
{
	List res;
	Node *tmp = this->head;
	for (int i = 0; i < this->size; ++i) {
		res.pushNode(tmp->data - value); 
		tmp = tmp->pNext;
	}
	return res;
}


List operator*(const List & obj, double value)
{
	List res;
	Node *tmp = obj.head;
	for (int i = 0; i < obj.size; ++i) {
		res.pushNode(tmp->data * value); 
		tmp = tmp->pNext;
	}
	return res;
}

List operator/(const List & obj, double value)
{
	List res;
	Node *tmp = obj.head;
	for (int i = 0; i < obj.size; ++i) {
		res.pushNode(tmp->data / value); 
		tmp = tmp->pNext;
	}
	return res;
}


bool List::operator==(const List & obj) {
	Node *tmpThis = head; 
	Node *tmpObj = obj.head;
	for (int i = 0; i < size; i++) {
		
		if (tmpThis->data != tmpObj->data)
			return false; 
		tmpThis = tmpThis->pNext; 
		tmpObj = tmpObj->pNext;
	}
	return true;
}


bool operator!=(List & obj1, const List & obj2) {
	return !(obj1 == obj2);
}