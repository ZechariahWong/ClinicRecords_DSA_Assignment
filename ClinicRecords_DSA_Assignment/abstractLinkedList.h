#pragma once
#include <iostream>
#include <string>
#include "medicine.h"

using namespace std;

class abstractLinkedList {
protected:
	struct Node
	{
		Node* next;							// pointer pointing to next item
	};

	Node* firstNode;
	int size;								// number of items in the list
public:
	abstractLinkedList() { size = 0; firstNode = NULL; };


	bool isEmpty();						// Empty = True 
	int getLength();						// getLength starts from 0

	// pure virtual functions: These functions will always be overwritten
	virtual void print() = 0;
	virtual bool remove(int index) = 0;

};