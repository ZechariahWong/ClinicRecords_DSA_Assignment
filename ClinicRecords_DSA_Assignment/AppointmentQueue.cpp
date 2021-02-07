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

// zech's version, will comment this out in the meantime
bool AppointmentQueue::enqueue(Patient* item)
{
	
	Node* newNode = new Node();
	newNode->item = *item;
	newNode->item.setQueueNo(item->getQueueNo());
	newNode->next = NULL;

	if (isEmpty())
	{
		cout << "Empty queue creating a new one..." << endl;
		frontNode = newNode;
	}
	else
	{
		Node* currentNode = NULL;
		currentNode = frontNode;
		// First checking to see if patient is already in the appointment queue
		// This is here to catch a duplicate in the case that there is no next pointer
		// It is an edge case for the first record and then trying to have the patient
		// add another record
		if (currentNode->item.getName () == newNode->item.getName () || backNode->item.getName () == newNode->item.getName())
		{
			cout << "This patient already has an issued queue number!\n";
			return false;
		}
		else {
			while (currentNode->next != NULL) {
				// If any point in time a duplicate name is found it will exit the method
				if (currentNode->item.getName () == newNode->item.getName ())
				{
					cout << currentNode->item.getName()<<" already has an issued queue number! " << newNode->item.getQueueNo() << "\n";
					// Setting current to the last node so it exits
					currentNode = backNode;
					return false;
				}
				// This checks to make sure there are no duplicate queue numbers, 
				// if there is a dupe it will set a new rand number and reset the loop
				else if (newNode->item.getQueueNo () == currentNode->item.getQueueNo ())
				{
					newNode->item.setQueueNo(rand()%9999);
					item->setQueueNo(newNode->item.getQueueNo());
					cout << "Duplicate queue number found reassigning... "<< newNode->item.getQueueNo() << " \n";
					currentNode = frontNode;
				}
				else {
					// If none of the above is true it will continue the loop as normal
					currentNode = currentNode->next;
				}
			}
			// Check the last node
			// This is more of an edge case and its a bit hard to test
			if (newNode->item.getQueueNo () == backNode->item.getQueueNo ())
			{
				newNode->item.setQueueNo (rand () % 9999);
				cout << "Duplicate queue number found reassigning... " << newNode->item.getQueueNo () << " \n";
				currentNode = frontNode;
			}
		}
		// Freeing up memory...
		currentNode = NULL;
		delete currentNode;
		backNode->next = newNode;
	}
	// If a duplicate is not found it will set the backNodes next to point to the new node
	cout << "No record found! Adding an appointment for " << newNode->item.getName () << endl;
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

//void track(Patient& item)
//{
//
//}

bool AppointmentQueue::isEmpty()
{
	return frontNode == NULL && backNode == NULL;
}

void AppointmentQueue::display()
{
	Node* temp = frontNode;

	if (!isEmpty())
	{
		while (temp != NULL)
		{
			std::cout << std::endl;
			std::cout << temp->item.getName() << std::endl;
			std::cout << temp->item.getPhoneNo() << std::endl;
			std::cout << temp->item.getNRIC() << std::endl;
			std::cout << temp->item.getQueueNo() << std::endl;
			temp = temp->next;
		}
	}
}