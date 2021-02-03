#pragma once
#include <string>
#include <iostream>

#include "patientBinaryNode.h"
#include "AVL_Tree.h"

class PatientDB_BST
{
private:
	PatientBinaryNode* root;

public:
	PatientDB_BST();

	//search
	PatientBinaryNode* search(Patient target);
	PatientBinaryNode* search(PatientBinaryNode* t, Patient target);

	//insert
	void insert(Patient item);
	void insert(PatientBinaryNode*& t, Patient item);

	//remove
	void remove(Patient target);
	void remove(PatientBinaryNode*& t, Patient target);

	//traverse inorder
	void inorder();
	void inorder(PatientBinaryNode* t);

	//traverse preorder
	void preorder();
	void preorder(PatientBinaryNode* t);

	//traverse postorder
	void postorder();
	void postorder(PatientBinaryNode* t);

	//check if binary search tree is empty
	bool isEmpty();

	//count number of nodes in binary search tree
	int countNodes();
	int countNodes(PatientBinaryNode* t);

	//compute height of binary search tree
	int getHeight();
	int getHeight(PatientBinaryNode* t);

	//check if binary search tree is balanced
	bool isBalanced();
	bool isBalanced(PatientBinaryNode* t);

	void display();
};