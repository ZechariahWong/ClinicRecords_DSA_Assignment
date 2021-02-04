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

bool AppointmentQueue::enqueue(Patient item)
{
	Node* newNode = new Node();
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
	{
		frontNode = newNode;
	}
	else
	{
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