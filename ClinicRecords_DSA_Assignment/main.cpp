#include "patient.h"

void initData () {
	Medicine* panadol = new Medicine ("Panadol", "For pain", 3.5);
	Medicine* coughSyr = new Medicine ("Cough Syrup", "For coughs", 0.9);
	Medicine* Strepsils = new Medicine ("Strepsils", "For sorethroats", 2.5);
	Patient* zech = new Patient ("Zech","+65 1234 5678","TXXXXXXXA");


	medicineStack* mainStack = new medicineStack ();
	mainStack->push (*panadol);
	mainStack->push (*coughSyr);
	mainStack->push (*Strepsils);
	mainStack->displayInOrder ();
	return;
}

void main () {
	initData ();
}