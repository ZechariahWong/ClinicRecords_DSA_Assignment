//#include "record.h"
#pragma once
#include "recordList.h"

class Patient {
private:
	string name;
	string phoneNo;
	string NRIC;
	recordList records;
	int queueNo; //NULL or 0 default value -> User is not in active queue

public:
	Patient ();
	Patient (string n, string hp, string nric);

	string getName();
	string getPhoneNo();
	string getNRIC();
	recordList getRecordList();
	int getQueueNo();
	void setQueueNo(int no);
	void addRecord(Record r);
};