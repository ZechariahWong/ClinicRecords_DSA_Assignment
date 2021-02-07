#pragma once
#include "patient.h"
#include "abstractLinkedList.h"

class patientList : public abstractLinkedList {
protected:
	struct patientNode : Node
	{
		Patient item;		// data item
		patientNode* next;
	};

	patientNode* firstNode;		// point to the first item

public:
	// Inherited functions taken feom abstractList
	// Constructor
	// getLength()
	// isEmpty()
	patientList();

	//Patient get(int index);
	Patient* get(int index);

	bool add(Patient item);
	//bool add(int index, Medicine item);
	bool remove(int index);
	bool clear();
	void print();
};