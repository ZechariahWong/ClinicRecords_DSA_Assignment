#include "record.h"

Record::Record () {};
Record::Record (string id, string note, medicineList meds, float total) {
	recordID = id;
	doctorNotes = note;
	medsGiven = meds;
	amtPayable = total;
};

string Record::getRecordID () { return recordID; };
string Record::getDoctorNotes () { return doctorNotes; };
medicineList Record::getMedsGiven () { return medsGiven; };
float Record::getBill () { return amtPayable; };

void Record::calcBill() {
	int length = medsGiven.getLength ();
	for (int i = 0; i < length; i++) {
		amtPayable += medsGiven.get (i).getPrice ();
	}
}


void Record::print () {
	cout << "ID: " << getRecordID() << endl
		<< "Notes: " << getDoctorNotes() << endl;
}