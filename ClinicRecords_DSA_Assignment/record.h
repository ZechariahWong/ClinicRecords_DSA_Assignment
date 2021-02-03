#pragma once
#include "medicineList.h"
class Record {
private:
	int recordID;
	string doctorNotes;				// This will just be some comments for the doctor to put in
	medicineList medsGiven;
	float amtPayable = 0;			// This will be the sum of the medicine price from medsGiven
public:
	Record();
	Record (int id, string note, medicineList meds);
	

	// Getter functions
	int			 getRecordID ();
	string		 getDoctorNotes ();
	medicineList getMedsGiven ();
	float getBill ();


	// Setters
	//void setRecordID (string id) ;
	void setDoctorNotes (string note) ;
	void calcBill ();						// Calculates the cost of all the meds
	//// setAmtPayable maybe irrelevant? 

	void print ();
};