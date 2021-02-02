#pragma once
#include <iostream>
#include <string>
#include "medicine.h"

using namespace std;

class abstractList {
protected:
	struct Node
	{
		Node* next;							// pointer pointing to next item
	};
	Node* firstNode;	
	int size;								// number of items in the list
public:
	abstractList () { size = 0; };

	
	bool isEmpty ();						// Empty = True 
	int getLength ();						// getLength starts from 0

	// pure virtual functions: These functions will always be overwritten
	virtual void print () = 0;
	virtual bool remove (int index) = 0;

	// for some reason this generates an error of the program trying to instantiate an abstract class
	// I think cause theres technically no "bool add(int index)" anywhere
	//virtual bool add (int index) = 0;				

};