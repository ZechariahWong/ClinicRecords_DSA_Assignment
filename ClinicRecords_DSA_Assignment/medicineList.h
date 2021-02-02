#pragma once
#include "medicine.h"
#include "abstractList.h"
class medicineList : public abstractList {
protected:
	struct medNode: Node
	{
		Medicine item;		// data item
		medNode* next;
	};
	medNode* firstNode;		// point to the first item
public:
	// Inherited functions taken feom abstractList
	// Constructor
	// getLength()
	// isEmpty()
	
	// Getting by Medicine index no
	Medicine get(int index);
	
	bool add(Medicine item);
	bool add(int index, Medicine item);
	
	bool remove(int index);
		
	void print ();
};