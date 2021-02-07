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
	Record (string id, string note, medicineList meds, float amtPayable);
	

	// Getter functions
	string		 getRecordID ();
	string		 getDoctorNotes ();
	medicineList getMedsGiven ();
	float getBill ();


	// Setters
	void setDoctorNotes (string note) ;
	void calcBill ();						// Calculates the cost of all the meds

	void print ();
};