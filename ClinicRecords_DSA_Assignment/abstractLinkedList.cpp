
#include "abstractLinkedList.h"

bool abstractLinkedList::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

int abstractLinkedList::getLength() { return size; };

//bool abstractList::add ()
//{
//	Node* newNode = new Node ();
//	newNode->next = NULL;
//
//	if (size == 0)
//	{
//		firstNode = newNode;
//	}
//	else
//	{
//		//Node *nextNode = new Node ();
//		//currentNode = firstNode;
//		Node* currentNode = firstNode;
//		while (currentNode->next != NULL)
//		{
//			currentNode = currentNode->next;
//		}
//		currentNode->next = newNode;
//	}
//	size++;
//	return true;
//}
//void abstractList::print ()
//{
//	Node* currentNode = firstNode;
//	for (int i = 0; i <= size - 1; i++)
//	{
//		cout << currentNode->item << endl;
//		currentNode = currentNode->next;
//	}
//	cout << "end" << endl;
//}
=======
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
