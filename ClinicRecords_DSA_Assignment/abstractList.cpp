#pragma once
#include "abstractList.h"

bool abstractList::isEmpty ()
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

int abstractList::getLength () { return size; };
