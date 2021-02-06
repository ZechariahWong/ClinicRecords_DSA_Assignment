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

void abstractLinkedList::clear () {
	if (!isEmpty())
	{
		Node* currentNode = firstNode;
		Node* nextNode = NULL;
		if (currentNode != nullptr) {
			nextNode = currentNode->next;
			currentNode = NULL;
			firstNode = nextNode;
		}
		else
		{
			currentNode = NULL;
		}
		size--;
		
		// If the list isnt empty repeat everything
		if (!isEmpty ()) {
			clear ();
		}
	}
}