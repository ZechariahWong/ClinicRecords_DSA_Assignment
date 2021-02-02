#pragma once
#include "medicineList.h"
class Record {
private:
	string recordID;
	string doctorNotes;				// This will just be some comments for the doctor to put in
	medicineList medsGiven;
	float amtPayable = 0;			// This will be the sum of the medicine price from medsGiven
public:
	Record();
	Record (string id, string note, medicineList meds);
	

	// Getter functions
	string		 getRecordID ();
	string		 getDoctorNotes ();
	medicineList getMedsGiven ();

	void calcBill ();
	float getBill ();

	//void setRecordID (string id) ;
	void setDoctorNotes (string note) ;
	//// setAmtPayable maybe irrelevant? Regardles 
	//// I will just have the function iterate 
	//// and amtPayable += medsGive[i].getPrice()
	//void setAmtPayable () ;
};