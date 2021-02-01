// medicineStack.h – Specification of medicineStack (Pointer-based implementation)
#pragma once
#include "medicine.h"


class medicineStack
{
private:
	struct Node
	{
		Medicine item;   // to store data
		Node* next;  // to point to next node
	};
	Node* topNode;

public:
	medicineStack ();		// constructor
	~medicineStack ();		// destructor
	bool push (Medicine item);
	//bool push(string item);
	bool pop ();
	void getTop (Medicine& item);
	bool isEmpty ();
	void displayInOrder();
	void displayInOrderOfInsertion();
};


