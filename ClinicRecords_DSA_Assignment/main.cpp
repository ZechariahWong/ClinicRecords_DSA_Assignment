#include "patient.h"
#include "recordList.h"


Medicine* panadol = new Medicine ("Panadol", "For pain", 3.5);
Medicine* coughSyr = new Medicine ("Cough Syrup", "For coughs", 0.9);
Medicine* Strepsils = new Medicine ("Strepsils", "For sorethroats", 2.5);
Patient* zech = new Patient ("Zech", "+65 1234 5678", "TXXXXXXXA");
recordList* medicineCollection = new recordList();

int main () {
	medicineCollection->add (*panadol);
	medicineCollection->add (*coughSyr);
	medicineCollection->add (*Strepsils);
	medicineCollection->print ();
	cout << endl;
	cout << "Medicine list index 1: " << medicineCollection->get (1).getName () << endl;
	cout << endl;
	cout << medicineCollection->isEmpty ();
	medicineCollection->remove (1);
	cout << endl;
	medicineCollection->print ();
	//mainStack->displayInOrder ();
	return 0;
}