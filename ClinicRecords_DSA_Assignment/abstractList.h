#pragma once
#include <iostream>
#include <string>
#include "medicine.h"

using namespace std;

class abstractList {
protected:
	struct Node
	{
		Node* next;	// pointer pointing to next item
	};
	Node* firstNode;	
	int size;					// number of items in the list
public:
	abstractList () { size = 0; };

	// Empty = True 
	bool isEmpty ();
	int getLength ();

	// pure virtual functions: These functions will always be overwritten
	virtual void print () = 0;
	//virtual bool add () = 0;		
	//virtual bool remove(int index) = 0;
};