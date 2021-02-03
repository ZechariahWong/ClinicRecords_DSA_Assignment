#pragma once
#include "recordList.h"

class Patient {
private:
	string name;
	string phoneNo;
	string NRIC;
	recordList records;
public:
	Patient ();
	Patient (string n, string hp, string nric);

	string getName();
	string getPhoneNo();
	string getNRIC();
	recordList getRecordList ();
	bool addRecord (Record item);
};