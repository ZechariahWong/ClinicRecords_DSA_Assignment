#pragma once
#include "patient.h"

struct PatientBinaryNode
{
	Patient item;
	PatientBinaryNode* right;
	PatientBinaryNode* left;
};