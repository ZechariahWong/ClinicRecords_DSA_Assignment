#include "patient.h"

Patient::Patient() { name = ""; phoneNo = ""; NRIC = ""; records = recordList(); queueNo = NULL; };
Patient::Patient (string n, string hp, string nric) {
	name = n;
	phoneNo = hp;
	NRIC = nric;
	records = recordList();
	queueNo = NULL;
};

string Patient::getName () { return name; }
string Patient::getPhoneNo () { return phoneNo; }
string Patient::getNRIC () { return NRIC; }

recordList Patient::getRecordList() { return records; }
int Patient::getQueueNo() { return queueNo; }
void Patient::setQueueNo(int no) { queueNo = no; }

void Patient::addRecord(Record r)
{
	records.add(r);
	cout << "A new record has been added into your records list." << endl;
}