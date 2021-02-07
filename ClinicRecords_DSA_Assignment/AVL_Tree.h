#pragma once
// AVL_Tree.h - AVL functions(Specification)
#pragma once
#include<iostream>
#include "patientBinaryNode.h"

using namespace std;

//template <typename Node>
void balanceTree(PatientBinaryNode*& t);

// AVL Tree functions
//template <typename Node>
PatientBinaryNode* balance(PatientBinaryNode* t);

//template <typename Node>
PatientBinaryNode* rotateLeft(PatientBinaryNode* node);

//template <typename Node>
PatientBinaryNode* rotateRight(PatientBinaryNode* node);

//template <typename Node>
PatientBinaryNode* rotateLeftRight(PatientBinaryNode* node);

//template <typename Node>
PatientBinaryNode* rotateRightLeft(PatientBinaryNode* node);

//template <typename Node>
int diff(PatientBinaryNode* t);

//template <typename Node>
int getHeight(PatientBinaryNode* t);