#include "patient.h"

Patient::Patient () {};
Patient::Patient (string n, string hp, string nric) {
	name = n;
	phoneNo = hp;
	NRIC = nric;
};

string Patient::getName () { return name; };
string Patient::getPhoneNo () { return phoneNo; };
string Patient::getNRIC () { return NRIC; };

//patientRecord Patient::getRecord (string id) {
//
//};