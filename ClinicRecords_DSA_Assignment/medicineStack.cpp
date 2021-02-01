#include "medicineStack.h"

medicineStack::medicineStack () {};
medicineStack::~medicineStack () {};


bool medicineStack::push (Medicine item) {
	cout << "Push" << endl;
	Node* newNode = new Node ();
	newNode->item = item;
	newNode->next = topNode;
	topNode = newNode;
	return true;
};

bool medicineStack::pop () {
	cout << "Pop" << endl;
	if (!isEmpty ()) {
		Node* tempNode = new Node ();
		tempNode = topNode->next;
		//cout << "Top node item: " << topNode->item <<endl;
		if (tempNode != NULL)
		{
			topNode->item = tempNode->item;
			topNode->next = tempNode->next;
			cout << "New topNode: " << topNode->item.getName() << endl;
			return true;
		}
		else {
			topNode = NULL;
			return true;
		}
	}
	else {
		cout << "Error topNode is null" << endl;
		return false;
	}
};
void medicineStack::getTop (Medicine& item) {
	cout << "getTop" << endl;
	if (!isEmpty ()) {
		item = topNode->item;
	}
	else
		cout << "Error list is empty" << endl;
};
bool medicineStack::isEmpty () {

	if (topNode == NULL)
		return true;
	else
		return false;
};
void medicineStack::displayInOrder () {
	cout << "Display in order" << endl;
	Node* tempNode = new Node ();
	tempNode = topNode;
	while (tempNode->next != NULL)
	{
		cout << "Node item: " << tempNode->item.getName() << endl;
		if (tempNode->next == NULL)
			break;
		else
			tempNode = tempNode->next;
	}
	cout << "Node item: " << tempNode->item.getName() << endl;
};
void medicineStack::displayInOrderOfInsertion () {
	cout << "Display in order of insertion" << endl;
	medicineStack* tempStack = new medicineStack();
	Node* tempNode = new Node ();
	tempNode = topNode;
	while (tempNode->next != NULL)
	{
		tempStack->push (tempNode->item);
		tempNode = tempNode->next;
	}
	tempStack->push (tempNode->item);
	tempStack->displayInOrder ();
};