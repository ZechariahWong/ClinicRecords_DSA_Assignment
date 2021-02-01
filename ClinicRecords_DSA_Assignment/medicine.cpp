#include "medicine.h"

// Constructors
Medicine::Medicine () {}
Medicine::Medicine (string n, string d, float p) {
	name = n;
	description = d;
	price = p;
}

// Basic getter function
string Medicine::getName () { return name; }
float Medicine::getPrice () { return price; }
string Medicine::getDescription () { return description; }

// Basic setter functions
void Medicine::setName (string n) { name = n; }
void Medicine::setPrice (float p) { price = p; }
void Medicine::setDescription (string d) { description = d; }