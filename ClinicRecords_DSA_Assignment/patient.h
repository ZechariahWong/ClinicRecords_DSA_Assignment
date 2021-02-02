#include "record.h"

class Patient {
private:
	string name;
	string phoneNo;
	string NRIC;
	//list<record> records;
public:
	Patient ();
	Patient (string n, string hp, string nric);

	string getName();
	string getPhoneNo();
	string getNRIC();
	//record getRecord (string id);
};