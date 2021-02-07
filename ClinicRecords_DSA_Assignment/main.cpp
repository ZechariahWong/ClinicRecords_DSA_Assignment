#pragma once
#include <string>
#include <stdlib.h>
#include <time.h>
#include "patient.h"
#include "recordList.h"
#include "PatientDB_BST.h"
#include "AppointmentQueue.h"


Medicine panadol = Medicine ("Panadol", "For pain", 3.5);
Medicine coughSyr = Medicine ("Cough Syrup", "For coughs", 0.9);
Medicine Strepsils = Medicine ("Strepsils", "For sorethroats", 2.5);

PatientDB_BST database = PatientDB_BST ();
AppointmentQueue aQueue = AppointmentQueue ();

medicineList medicineCollection = medicineList ();

void menuDisplay ()
{
	cout << "\nClinic Appointment System (v0.69)" << endl;
	cout << "=================================" << endl;
	cout << "1) Register Patient" << endl;
	cout << "2) Add appointment information" << endl; //add record to patient
	cout << "3) Issue Queue No." << endl;
	cout << "4) View all patients" << endl;
	cout << "5) Search patient" << endl; //displays all patients records
	cout << "6) Call next queue number" << endl; //dequeue 1-by-1
	cout << "7) Exit" << endl;
}

void registerPatient ()
{
	string name, number, ic;

	cout << "Patient's Name: " << endl;
	cin >> name;
	cout << endl;

	cout << "Patient's Contact Number: " << endl;
	cin >> number;
	cout << endl;

	cout << "Patient's NRIC: " << endl;
	cin >> ic;
	cout << endl;

	Patient patient = Patient (name, number, ic);
	database.insert (patient);
	cout << "Patient successfully registered." << endl;
	cout << endl;
}
void searchPatient ()
{
	string name;
	cout << "Insert Patient's Name: " << endl;
	cin >> name;

	database.resultSearch (name);

	cout << "Possible patient(s):" << endl;
	database.displaySearchResults ();
}
void enterMedicineDetails (medicineList medsGiven, float& subTotal) //helper func for add appt info
{
	string medsName, medsDesc, amt;

	cout << "Enter medicine name given: " << endl;
	cin >> medsName;
	cout << endl;

	cout << "Enter medicine description given: " << endl;
	cin >> medsDesc;
	cout << endl;

	cout << "Enter medicine price: " << endl;
	cin >> amt;
	cout << endl;

	float medAmt = atof (amt.c_str ());
	Medicine m = Medicine (medsName, medsDesc, medAmt);
	subTotal += medAmt;
	medsGiven.add (m);
}
void addApptInfo ()
{
	searchPatient ();
	int patientChoice;
	cout << "Select result (1 being the topmost patient): ";
	cin >> patientChoice;
	Patient* patient = database.searchResults.get (patientChoice - 1);

	string recordId, notes;
	medicineList medsGiven = medicineList ();
	float subTotal = 0;

	cout << "Enter Appointment ID: " << endl;
	cin >> recordId;
	cout << endl;

	cout << "Enter doctor's notes: " << endl;
	cin >> notes;
	cout << endl;

	enterMedicineDetails (medsGiven, subTotal);
	string repeat_choice = "Y";

	while (repeat_choice == "Y")
	{
		cout << "Enter medicine again? (Y/N)" << endl;
		cin >> repeat_choice;
		if (repeat_choice == "Y")
		{
			enterMedicineDetails (medsGiven, subTotal);
		}
	}

	Record r = Record (recordId, notes, medsGiven, subTotal);
	patient->addRecord (r);

	cout << "Record successfully added to patient data." << endl;
}

void issueQueueNo ()
{
	searchPatient ();
	int patientChoice;
	cout << "Select result (1 being the topmost patient): ";
	cin >> patientChoice;
	Patient* patient = database.searchResults.get (patientChoice - 1); // points to patient in search result
	Patient* patientContext = &database.search (*patient)->item; // point to address of patient retrieved from database search
	cout << "\n" << patientContext->getName () << " selected." << endl; // for debugging

	patientContext->setQueueNo (rand () % 9999); // patient in DB changes queue no
	aQueue.enqueue (patientContext);
}

void viewAllPatients ()
{
	// debug database print
	cout << "===DATABASE===" << endl;
	database.display ();

	// debug queue print
	cout << "===QUEUE===" << endl;
	aQueue.display ();

	cout << endl;
}

void callNextQueueNumber ()
{
	Patient p;
	if (!aQueue.dequeue (p))
		cout << "Queue is empty." << endl;
	else
		cout << "Calling out to: " << p.getName () << ", with queue number " << p.getQueueNo () << endl;
}

void menuChoice ()
{
	int choice = 0;
	while (choice != 7)
	{
		cout << "Choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			registerPatient ();
			break;

		case 2:
			addApptInfo ();
			break;

		case 3:
			issueQueueNo ();
			break;

		case 4:
			viewAllPatients ();
			break;

		case 5:
			searchPatient ();
			break;

		case 6:
			callNextQueueNumber ();
			break;
		case 7:
			break;

		default:
			cout << "Invalid choice, please select a valid choice." << endl;
			break;
		}
		menuDisplay ();
	}
}

int main () {
	srand (time (NULL));
	Patient zech = Patient ("zech", "123", "001");
	Patient kelvin = Patient ("kelvin", "321", "002");
	Patient patient = Patient ("patient", "321213", "003");
	Patient patient2 = Patient ("patient2", "54321", "004");
	database.insert (zech);
	database.insert (kelvin);
	database.insert (patient);
	database.insert (patient2);

	menuDisplay ();
	menuChoice ();
	return 0;
}