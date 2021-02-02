#include "patient.h"

Patient::Patient() { name = ""; phoneNo = ""; NRIC = ""; records = new recordList(); };
Patient::Patient (string n, string hp, string nric) {
	name = n;
	phoneNo = hp;
	NRIC = nric;
	records = new recordList();
};

string Patient::getName () { return name; }
string Patient::getPhoneNo () { return phoneNo; }
string Patient::getNRIC () { return NRIC; }

recordList* Patient::getRecordList() { return records; }

void Patient::addRecord(Record r)
{
	records->add(r);
	cout << "A new record is added into your records list." << endl;
}
