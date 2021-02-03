#pragma once
#include <string>
#include "patient.h"
#include "recordList.h"

Medicine panadol = Medicine("Panadol", "For pain", 3.5);
Medicine coughSyr = Medicine("Cough Syrup", "For coughs", 0.9);
Medicine Strepsils = Medicine("Strepsils", "For sorethroats", 2.5);

Patient zech = Patient("Zech", "+65 1234 5678", "TXXXXXXXA");
medicineList medicineCollection = medicineList();

int main () {
	medicineCollection.add(panadol);
	medicineCollection.add(coughSyr);
	medicineCollection.add(Strepsils);
	Record myRec = Record("1", "Patient is alive and well", medicineCollection);
	zech.addRecord(myRec);
	return 0;
}