#include "recordList.h"

recordList::recordList() { size = 0; firstNode = NULL; };

bool recordList::add(Record item)
{
	recNode* newNode = new recNode();
	newNode->item = item;
	newNode->next = NULL;

	if (size == 0)
	{
		firstNode = newNode;
	}
	else
	{
		//recNode *nextNode = new recNode ();
		//currentNode = firstNode;
		recNode* currentNode = firstNode;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	size++;
	return true;
}

bool recordList::add(int index, Record item)
{
	if (index <= size - 1)
	{
		recNode* newNode = new recNode();
		newNode->item = item;
		newNode->next = NULL;
		cout << "Being added:" << newNode->item.getRecordID() << endl;
		//cout << newNode->next << endl;
		// Using a "firstNode" as it has to go through the entire recordList
		recNode* currentNode = firstNode;
		if (index == 0) {
			newNode->next = currentNode;
			firstNode = newNode;
		}
		else {
			for (int i = 0; i < index - 1; i++)
			{
				currentNode = currentNode->next;
			}
			// index - 1 means that it will stop just before the index 
			// effectively 'taking' its place
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
		size++;
	}

	return true;
}

bool recordList::remove(int index)
{
	if (0 <= index && index <= size - 1)
	{

		if (index == 0)
		{
			if (size == 1)
			{
				delete firstNode;
				firstNode = NULL;
			}
			else
			{
				cout << "Being removed: " << firstNode->item.getRecordID() << endl;
				firstNode = firstNode->next;
			}
			size--;
		}
		else
		{
			recNode* currentNode = firstNode;
			recNode* prevNode = NULL;
			for (int i = 0; i < index; i++)
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			cout << "Being removed: " << currentNode->item.getRecordID() << endl;
			prevNode->next = currentNode->next;
			delete currentNode;
			size--;
		}
		return true;
	}
	else {
		return false;
	}
	//size--;
}

Record recordList::get(int index)
{
	if (index <= size) {
		recNode* currentNode = firstNode;
		for (int i = 0; i < index; i++) {
			currentNode = currentNode->next;
		}
		//cout << "Item retrieved: " << currentNode->item.getName () << endl;
		return currentNode->item;
	}
	else {
		cout << "Invalid index" << endl;
	}
}

//bool recordList::isEmpty ()
//{
//	if (size == 0)
//		return true;
//	else
//		return false;
//}

void recordList::print()
{
	recNode* currentNode = firstNode;
	cout << "================" << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << "Record ID: " << currentNode->item.getRecordID () << endl
			<< "Doctor's notes: " << currentNode->item.getDoctorNotes () << endl
			<< "Medicine issued: ";
		currentNode->item.getMedsGiven ().print();
		currentNode = currentNode->next;
	}
	cout << "================" << endl;
	//cout << "end" << endl;
}