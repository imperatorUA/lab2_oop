#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "MyStruct.h"

using namespace std;

Stack::Stack()
{
	_size = 0;
	head = NULL;
}

Stack::~Stack()
{
	MyStruct *head = this->head;
	MyStruct *next = head->next;
	for (int i = 0; i < this->_size; i++)
	{		
		next = head->next;
		delete head;
		head = next;
	}

	delete next;
	delete head;
}

int Stack::size() const {
	return  this->_size;
}

bool Stack::isEmpty() const {
	return _size == 0;
}

char* Stack::toString() const {
	char *description = new char[256]{ NULL };
	MyStruct *temp = head;

	strcat(description, "Stack\nHead->");
	for (int i = 0; i < _size; i++) {
		if (i != 0) {
			strcat(description, ", ");
		}

		char *val = new char[256]{ NULL };
		itoa(temp->value, val, 10);
		temp = temp->next;
		strcat(description, val);
		delete val;

	}
	strcat(description, "<-Tail");

	return description;
}

bool Stack::push(int value) {
	try
	{
		MyStruct *ptr_str = new MyStruct(value);

		if (isEmpty()) {
			this->head = ptr_str;
		}
		else {
			ptr_str->next = this->head;
			this->head = ptr_str;
		}
		_size++;
	}
	catch (const std::exception&)
	{
		return false;
	}
	
	return true;
};

int Stack::pop() {
	if (this->isEmpty())
		throw "Error: stck empty";

	int temp = this->head->value;
	this->head = this->head->next;
	_size--;
	return temp;
};

int Stack::peek() const {
	if (this->isEmpty())
		throw "Error: stck empty";
	return head->value;
};