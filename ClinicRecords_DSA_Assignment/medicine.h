#pragma once

#include <iostream>
#include <string>
using namespace std;

class Medicine {
private:
	string name;
	string description;
	float price;
public:
	Medicine ();
	Medicine (string n, string d, float p);
	string getName ();
	string getDescription ();
	float getPrice ();

	void setName (string n);
	void setDescription (string d);
	void setPrice (float p);
};