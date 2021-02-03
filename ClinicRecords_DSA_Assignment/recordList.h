#pragma once
#include "record.h"
#include "abstractLinkedList.h"
//#include "medicineList.h"

class recordList : public  abstractLinkedList{
protected:
	struct recNode : Node
	{
		Record item;		// data item
		recNode* next;
	};

	recNode* firstNode;		// point to the first item

public:
	// Inherited functions taken feom abstractList
	// Constructor
	// getLength()
	// isEmpty()
	recordList();

	// Getting by Medicine index no
	Record get(int index);

	bool add(Record item);
	bool add(int index, Record item);

	bool remove(int index);

	void print();
};
