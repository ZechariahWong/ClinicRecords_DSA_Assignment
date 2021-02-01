#include "patientRecord.h"

patientRecord::patientRecord () {}
patientRecord::patientRecord (string id, string note, medicineStack meds) {
	recordID = id;
	doctorNotes = note;
	//amtPayable = getAmtPayable ();
	medsGiven = meds;
}

string patientRecord::getRecordID () { return recordID; }
string patientRecord::getDoctorNotes () { return doctorNotes; }
//float patientRecord::getAmtPayable () {
	//for (Medicine m; i < medsGiven.size(); i++)
	//{
	//
	//	amtPayable += medsGiven[i].getPrice ();
	//}
//}


//void patientRecord::setRecordID () {}
//void patientRecord::setDoctorNotes () {}
//void patientRecord::setAmtPayable () {}