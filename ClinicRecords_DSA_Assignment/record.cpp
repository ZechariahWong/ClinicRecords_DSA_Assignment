#include "record.h"

Record::Record () {};
Record::Record (string id, string note, medicineList meds) {
	recordID = id;
	doctorNotes = note;
	//amtPayable = getAmtPayable ();
	medsGiven = meds;
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


//float record::getAmtPayable () {
	//for (Medicine m; i < medsGiven.size(); i++)
	//{
	//
	//	amtPayable += medsGiven[i].getPrice ();
	//}
//}


//void record::setRecordID () {}
//void record::setDoctorNotes () {}
//void record::setAmtPayable () {}