#pragma once
#include "patient.h"
#include "recordList.h"


Medicine panadol = Medicine ("Panadol", "For pain", 3.5);
Medicine coughSyr = Medicine ("Cough Syrup", "For coughs", 0.9);
Medicine Strepsils = Medicine ("Strepsils", "For sorethroats", 2.5);

medicineList* medicineCollection = new medicineList();

Record zechRec1 = Record (1, "nOTE", *medicineCollection);
Record zechRec2 = Record (2, "nOTE TWO", *medicineCollection);

recordList* recList = new recordList();

Patient zech = Patient ("Zech", "+65 1234 5678", "TXXXXXXXA");


int main () {
	medicineCollection->add (panadol);
	medicineCollection->add (Strepsils);
	medicineCollection->print ();

	recList->add (zechRec1);
	recList->add (zechRec2);
	recList->print ();

	cout << endl << "PatientStuff" << endl;
	

	zech.addRecord (zechRec1);
	zech.addRecord (zechRec2);

	//zech.getRecordList().add(zechRec1);
	zech.getRecordList().print ();
	//cout << "Patient records:" << zech.getRecordList () << endl;

	return 0;
}