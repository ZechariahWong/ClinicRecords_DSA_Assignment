#pragma once
#include "abstractLinkedList.h"

bool abstractLinkedList::isEmpty ()
{
	if (size == 0) {
		//cout << "empty" << endl;
		return true;
	}
		
	else {
		//cout << "Not empty" << endl;
		return false;
	}	
}

int abstractLinkedList::getLength () { return size; };
