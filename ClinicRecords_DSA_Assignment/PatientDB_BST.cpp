#include "PatientDB_BST.h"

PatientDB_BST::PatientDB_BST()
{
	root = NULL;
}

void PatientDB_BST::inorder()
{
	if (isEmpty())
		std::cout << "No patient found" << std::endl;
	else
		inorder(root);
}

void PatientDB_BST::inorder(PatientBinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		std::cout << std::endl;
		std::cout << t->item.getName() << std::endl;
		std::cout << t->item.getPhoneNo() << std::endl;
		std::cout << t->item.getNRIC() << std::endl;
		inorder(t->right);
	}
}

void PatientDB_BST::preorder()
{
	if (isEmpty())
		std::cout << "No patient found" << std::endl;
	else
		preorder(root);
}

void PatientDB_BST::preorder(PatientBinaryNode* t)
{
	if (t != NULL)
	{
		std::cout << t->item.getName() << std::endl;
		preorder(t->left);
		preorder(t->right);
	}
}

void PatientDB_BST::postorder()
{
	if (isEmpty())
		std::cout << "No patient found" << std::endl;
	else
		postorder(root);
}

void PatientDB_BST::postorder(PatientBinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		std::cout << t->item.getName() << std::endl;
	}
}

PatientBinaryNode* PatientDB_BST::search(Patient target)
{
	return search(root, target);
}

PatientBinaryNode* PatientDB_BST::search(PatientBinaryNode* t, Patient target)
{
	if (t == NULL)
		return NULL;
	else
	{
		if (t->item.getName() == target.getName())
			return t;
		else
		{
			if (target.getName() < t->item.getName())
				return search(t->left, target);
			else
				return search(t->right, target);
		}
	}
}

void PatientDB_BST::insert(Patient target)
{
	insert(root, target);
}

void PatientDB_BST::insert(PatientBinaryNode*& t, Patient target)
{
	if (t == NULL)
	{
		PatientBinaryNode* newNode = new PatientBinaryNode;
		newNode->item = target;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}
	else if (target.getName() < t->item.getName())
		insert(t->left, target);
	else
		insert(t->right, target);

	t = balance(t);
}

void PatientDB_BST::remove(Patient target)
{
	remove(root, target);
	balanceTree(root);
}

void PatientDB_BST::remove(PatientBinaryNode*& t, Patient target)
{
	if (t != NULL)
	{
		if (target.getName() < t->item.getName())
			remove(t->left, target);
		else if (target.getName() > t->item.getName())
			remove(t->right, target);
		else //found node with same patient val
		{
			//if node has no child
			if (t->left == NULL && t->right == NULL)
			{
				PatientBinaryNode* temp = t;
				t = NULL;
				delete temp;
			}
			//if node has one child
			else if (t->left == NULL)
			{
				PatientBinaryNode* temp = t;
				if (t == root)
					root = t->right;
				else
					t = t->right;
				delete temp;
			}
			else if (t->right == NULL)
			{
				PatientBinaryNode* temp = t;
				if (t == root)
					root = t->left;
				else
					t = t->left;
				delete temp;
			}
			//if node has 2 children
			else
			{
				PatientBinaryNode* successor = t->left;
				while (successor->right != NULL)
					successor = successor->right;

				Patient patient = successor->item;
				remove(t->left, patient);
				t->item = patient;
			}
		}
	}
}

bool PatientDB_BST::isEmpty()
{
	return root == NULL;
}

int PatientDB_BST::countNodes()
{
	int count = 0;
	if (!isEmpty())
	{
		count = countNodes(root);
	}

	return count;
}

int PatientDB_BST::countNodes(PatientBinaryNode* t)
{
	int count = 1;

	if (t != NULL)
	{
		count += countNodes(t->left);
		count += countNodes(t->right);
	}

	return count;
}

int PatientDB_BST::getHeight()
{
	int h = 1;
	if (!isEmpty())
	{
		h += getHeight(root);
	}

	return h;
}

int PatientDB_BST::getHeight(PatientBinaryNode* t)
{
	//or can use countNodes and plug a formula to determine the height

	int leftH = 0;
	int rightH = 0;

	if (t != NULL)
	{
		leftH += getHeight(t->left);
		rightH += getHeight(t->right);
		return (leftH > rightH ? leftH : rightH);
	}

	return 0;
}

bool PatientDB_BST::isBalanced()
{
	return isBalanced(root);
}

bool PatientDB_BST::isBalanced(PatientBinaryNode* t)
{
	if (t != NULL)
	{
		return true;
	}

	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	if (abs(leftHeight - rightHeight) > 1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);
}

void PatientDB_BST::display()
{
	inorder();
}