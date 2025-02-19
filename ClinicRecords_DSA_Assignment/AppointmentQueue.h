#pragma once
#include <iostream>
#include <cstdlib>			// Using this for the rand() function
#include "patient.h"

class AppointmentQueue
{
private:
	struct Node
	{
		Patient item;
		Node* next;
	};

	Node* frontNode;
	Node* backNode;
public:
	AppointmentQueue ();
	~AppointmentQueue ();

	bool enqueue (Patient* p);
	bool dequeue ();
	bool dequeue (Patient& p);
	Patient getFront ();
	void getFront (Patient& p);
	bool isEmpty ();
	void display ();
};