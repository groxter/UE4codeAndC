// cooperativeMultitaskingApplication.cpp : Defines the entry point for the console application.
// Antonio Garcia Luque

#include<iostream>
#include "stdafx.h"
#include "Coordinator.h"
#include "Task.h"

Node* setRoot(Node*);
void insertLeft(Node*);
void insertRight(Node*);
void insert(Node*);
void printTree(Node*);

int main()  // test plan to test the implementation (if you want to add more tasks you have tu change SIZE 
{           // in Coordinator.h example 7 Tasks then SIZE = 7

	Node *tree = NULL; // negative case (return false)
	tree = setRoot(tree); 
	for(int x = 0; x < 1000; x++) insertLeft(tree);

	Node* tree2 = NULL; // positive case (return true)
	tree2 = setRoot(tree2);
	insertLeft(tree);
	insertRight(tree);

	Node* tree3 = NULL; // positive case (return true)
	tree3 = setRoot(tree3);
	for (int x = 0; x < 200; x++) insertRight(tree3);
	for (int x = 0; x < 199; x++) insertLeft(tree3);


	Node* tree4 = NULL; // positive case (return true)
	tree4 = setRoot(tree4);
	for (int x = 0; x < 4008; x++) insertRight(tree4);
	for (int x = 0; x < 4009; x++) insertLeft(tree4);

	Node* tree5 = NULL; // negative case (return false)
	tree5 = setRoot(tree5);
	for (int x = 0; x < 3007; x++) insertRight(tree5);
	for (int x = 0; x < 4009; x++) insertLeft(tree5);

	Node* tree6 = NULL; // negative case (return false)
	tree6 = setRoot(tree6);
	insert(tree6);

	Task t(tree ,1);
	Task t2(tree2 ,2);
	Task t3(tree3, 3);
	Task t4(tree4, 4);
	Task t5(tree5, 5);
	Task t6(tree6, 6);

	Coordinator c;
	c.tasks[0] = &t;
	c.tasks[1] = &t2;
	c.tasks[2] = &t3;
	c.tasks[3] = &t4;
	c.tasks[4] = &t5;
	c.tasks[5] = &t6;

	return c.manageTasks();
	
}

Node* setRoot(Node* tree)
{
	tree = new Node;
	tree->data = 10;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}

void insertLeft(Node* tree)
{
	if (!tree->left)
	{
		tree->left = new Node;
		tree->left->data = 0;
		tree->left->left = NULL;
		tree->left->right = NULL;
	}
	else
	{
		insertLeft(tree->left);
	}
}

void insertRight(Node* tree)
{
	if (!tree->right)
	{
		tree->right = new Node;
		tree->right->data = 1;
		tree->right->left = NULL;
		tree->right->right = NULL;
	}
	else
	{
		insertRight(tree->right);
	}
}

void insert(Node* tree)
{
	if (!tree->left)
	{
		tree->left = new Node;
		tree->left->data = 1;
		tree->left->left = NULL;
		tree->left->right = NULL;

	}

	if (!tree->right)
	{
		tree->right = new Node;
		tree->right->data = 1;
		tree->right->left = new Node;
		tree->right->right = new Node;
		tree->right->left->right = new Node;
		tree->right->left->left = NULL;
		tree->right->left->right->left = NULL;
		tree->right->left->right->right = NULL;
		tree->right->right->left = NULL;
		tree->right->right->right = NULL;
	}

}

void printTree(Node* tree)
{
	if (tree)
	{
		cout << tree->data << endl;
		printTree(tree->left);
		printTree(tree->right);
	}
}