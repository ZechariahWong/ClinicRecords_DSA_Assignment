#pragma once
#include <string>
#include "patient.h"
#include "recordList.h"
#include "PatientDB_BST.h"

Medicine panadol = Medicine("Panadol", "For pain", 3.5);
Medicine coughSyr = Medicine("Cough Syrup", "For coughs", 0.9);
Medicine Strepsils = Medicine("Strepsils", "For sorethroats", 2.5);

PatientDB_BST database = PatientDB_BST();

Patient zech = Patient("Zech", "+65 1234 5678", "TXXXXXXXA");
medicineList medicineCollection = medicineList();

// subject to required modifications
void menuDisplay()
{
	cout << "Clinic Appointment System (v0.69)" << endl;
	cout << "=================================" << endl;
	cout << "1) Register Patient" << endl;
	cout << "2) Add appointment information" << endl; //add record to patient
	cout << "3) Issue Queue No." << endl;
	cout << "4) View all patients" << endl;
	cout << "5) Search patient" << endl; //displays all patients records
	cout << "6) Exit" << endl;
}

void registerPatient()
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

	Patient newPatient = Patient(name, number, ic);
	database.insert(newPatient);
	cout << "Patient successfully registered." << endl;
	cout << endl;
}

void addApptInfo()
{
	//to-do
}

void issueQueueNo()
{
	//to-do
}

void viewAllPatients()
{
	database.display();
	std::cout << std::endl;
}

void searchPatient()
{
	//to-do
}

void menuChoice()
{
	int choice = 0;
	while (choice != 6)
	{
		cout << "Choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			registerPatient();
			break;

		case 2:
			addApptInfo();
			break;

		case 3:
			issueQueueNo();
			break;

		case 4:
			viewAllPatients();
			break;

		case 5:
			searchPatient();
			break;

		case 6:
			break;

		default:
			cout << "Invalid choice, please select a valid choice." << endl;
			break;
		}
	}
}

int main() {
	//medicineCollection.add(panadol);
	//medicineCollection.add(coughSyr);
	//medicineCollection.add(Strepsils);
	//Record myRec = Record("1", "Patient is alive and well", medicineCollection);
	////medicineCollection->print();

	//zech.addRecord(myRec);
	//zech.getRecordList().print();
	////zech.getRecordList()->get(1).getMedsGiven().get(1).getName();

	//cout << endl;
	//Record r = zech.getRecordList().get(0);
	//medicineList ml = r.getMedsGiven();
	//int test = ml.getLength();
	//Medicine m = ml.get(0); //code breaks here

	//cout << "Medicine list index 1: " << zech.getRecordList().get(0).getMedsGiven().get(1).getName() << endl; //works now
	//cout << endl;
	//cout << medicineCollection.isEmpty();
	//medicineCollection.remove(1);
	//cout << endl;
	//medicineCollection.print();
	//cout << medicineCollection.getLength() << endl;
	//mainStack->displayInOrder ();
	menuDisplay();
	menuChoice();

	return 0;
}