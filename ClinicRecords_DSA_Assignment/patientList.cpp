#include "patientList.h"

patientList::patientList() { size = 0; firstNode = NULL; };

bool patientList::add(Patient item)
{
	patientNode* newNode = new patientNode();
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
	{
		firstNode = newNode;
	}
	else
	{
		//patientNode *nextNode = new patientNode ();
		//currentNode = firstNode;
		patientNode* currentNode = firstNode;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	size++;
	return true;
}

bool patientList::remove(int index)
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
			patientNode* currentNode = firstNode;
			patientNode* prevNode = NULL;
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
		return true;
	}
	else {
		return false;
	}
	//size--;
}

Patient patientList::get(int index)
{
	if (index <= size) {
		patientNode* currentNode = firstNode;
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

bool patientList::clear()
{
	while (size > 0)
	{
		remove(size - 1);
	}

	return true;
}

void patientList::print()
{
	patientNode* currentNode = firstNode;
	for (int i = 0; i <= size - 1; i++)
	{
		cout << currentNode->item.getName() << endl;
		currentNode = currentNode->next;
	}
	//cout << "end" << endl;
}