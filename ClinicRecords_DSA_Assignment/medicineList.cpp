#include "medicineList.h"

medicineList::medicineList() { size = 0; firstNode = NULL; };

bool medicineList::add (Medicine item)
{
	medNode* newNode = new medNode ();
	newNode->item = item;
	newNode->next = NULL;

	if (size == 0)
	{
		firstNode = newNode;
	}
	else
	{
		medNode* currentNode = firstNode;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	size++;
	return true;
}

bool medicineList::add (int index, Medicine item)
{
	if (index <= size - 1)
	{
		medNode* newNode = new medNode ();
		newNode->item = item;
		newNode->next = NULL;
		cout << "Being added:" << newNode->item.getName() << endl;
		medNode* currentNode = firstNode;
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

bool medicineList::remove (int index)
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
				cout << "Being removed: " << firstNode->item.getName() << endl;
				firstNode = firstNode->next;
			}
			size--;
		}
		else
		{
			medNode* currentNode = firstNode;
			medNode* prevNode = NULL;
			for (int i = 0; i < index; i++)
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			cout << "Being removed: " << currentNode->item.getName() << endl;
			prevNode->next = currentNode->next;
			delete currentNode;
			size--;
		}
		// I think it should work if we put size--; here but I dont want to make such a last minute change after all the testing
		return true;
	}
	else {
		return false;
	}
}

Medicine medicineList::get (int index)
{
	if (index <= size) {
		medNode* currentNode = firstNode;
		for (int i = 0; i < index; i++) {
			currentNode = currentNode->next;
		}
		return currentNode->item;
	}
	else {
		cout << "Invalid index" << endl;
	}
}


void medicineList::print ()
{
	medNode* currentNode = firstNode;
	for (int i = 0; i <= size - 1; i++)
	{
		if (i != size - 1) {
			cout << currentNode->item.getName ()<< ", ";
		}
		else
		{
			cout << currentNode->item.getName () << ".";
		}
		currentNode = currentNode->next;
	}
	cout << endl;
}