#include "patientRecord.h"

class Patient {
private:
	string name;
	string phoneNo;
	string NRIC;
	list<patientRecord> records;
public:
	Patient ();
	Patient (string n, string hp, string nric);

	string getName();
	string getPhoneNo();
	string getNRIC();
	patientRecord getRecord (string id);
};