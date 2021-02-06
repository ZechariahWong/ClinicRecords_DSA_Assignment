#include "AppointmentQueue.h"

AppointmentQueue::AppointmentQueue()
{
	frontNode = NULL;
	backNode = NULL;
}

AppointmentQueue::~AppointmentQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}

	delete frontNode;
	delete backNode;
	frontNode = NULL;
	backNode = NULL;
}

bool AppointmentQueue::enqueue(Patient* item)
{
	
	Node* newNode = new Node();
	newNode->item = *item;
	newNode->next = NULL;
	cout << "Enqueue new: " << newNode->item.getName () << endl;

	if (isEmpty())
	{
		newNode->item.setQueueNo (rand () % 9999);
		frontNode = newNode;
	}
	else
	{
		Node* currentNode = new Node ();
		currentNode = frontNode;
		// First checking to see if patient is already in the appointment queue
		while (currentNode->next != NULL) {
			cout << "Current: " << currentNode->item.getName () << endl;
			if (currentNode->item.getName () == newNode->item.getName ())
			{
				cout <<"Current "<< currentNode->item.getName () << endl << "New " << newNode->item.getName() << endl;
				cout << "This patient already has an issued queue number!\n";
				break;
			}
			currentNode = currentNode->next;
		}
		//currentNode = frontNode;
		//while (currentNode->next != NULL) {
		//	if (newNode->item.getQueueNo () == currentNode->item.getQueueNo())
		//	{
		//		newNode->item.setQueueNo (rand () % 9999);
		//		currentNode = frontNode;					
		//	}
		//	else
		//	{
		//		currentNode = currentNode->next;
		//	}
		//}
		//delete currentNode;
		backNode->next = newNode;
	}

	backNode = newNode;
	return true;
}

bool AppointmentQueue::dequeue()
{
	Node* temp = frontNode;

	if (!isEmpty())
	{
		if (frontNode == backNode)
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
		{
			frontNode = frontNode->next;
		}

		delete temp;
		temp = NULL;
		return true;
	}

	return false;
}

bool AppointmentQueue::dequeue(Patient& item)
{
	Node* temp = frontNode;

	if (!isEmpty())
	{
		item = frontNode->item;
		frontNode = frontNode->next;
		delete temp;
		temp = NULL;
		return true;
	}

	return false;
}

Patient AppointmentQueue::getFront()
{
	if (!isEmpty())
		return frontNode->item;
	else
		cout << "Queue is empty" << endl;
}

void AppointmentQueue::getFront(Patient& item)
{
	item = frontNode->item;
}

void track(Patient& item)
{

}

bool AppointmentQueue::isEmpty()
{
	return frontNode == NULL && backNode == NULL;
}