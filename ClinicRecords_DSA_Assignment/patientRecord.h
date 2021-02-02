#include "medicineList.h"
#include <list>

class patientRecord {
private:
	string recordID;
	string doctorNotes;			// This will just be some comments for the doctor to put in
	float amtPayable = 0;			// This will be the sum of the medicine price from medsGiven
	medicineList medsGiven;
public:
	patientRecord();
	patientRecord (string id, string note, medicineList meds);
	string	getRecordID () ;
	string	getDoctorNotes () ;
	//float	getAmtPayable () ;
	//void setRecordID (string id) ;
	//void setDoctorNotes (string note) ;
	//// setAmtPayable maybe irrelevant? Regardles 
	//// I will just have the function iterate 
	//// and amtPayable += medsGive[i].getPrice()
	//void setAmtPayable () ;
};