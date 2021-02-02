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
	//medicineCollection->print();

	zech.addRecord(myRec);
	zech.getRecordList().print();
	//zech.getRecordList()->get(1).getMedsGiven().get(1).getName();

	//cout << endl;
	//Record r = zech.getRecordList().get(0);
	//medicineList ml = r.getMedsGiven();
	//int test = ml.getLength();
	//Medicine m = ml.get(0); //code breaks here

	cout << "Medicine list index 1: " << zech.getRecordList().get(0).getMedsGiven().get(1).getName() << endl; //works now
	cout << endl;
	cout << medicineCollection.isEmpty();
	medicineCollection.remove(1);
	cout << endl;
	medicineCollection.print();
	cout << medicineCollection.getLength() << endl;
	//mainStack->displayInOrder ();
	return 0;
}