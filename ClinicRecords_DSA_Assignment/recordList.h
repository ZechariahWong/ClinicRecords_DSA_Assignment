#pragma once
#include "record.h"
#include "abstractList.h"

class recordList : public  abstractList{
private:
	struct recordNode : Node {
		Record item;
		recordNode* next;
	};
	recordNode* firstNode;
public:
	// Inherited functions taken feom abstractList
	// Constructor
	// getLength()
	// isEmpty()
	
	// Getting by Medicine index no
	Record get (int index);

	bool add (Record item);
	bool add (int index, Record item);

	bool remove (int index);

	void print ();
};