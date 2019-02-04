/*
  1] Do level order traversal and print the first and last nodes of every level.
  https://www.geeksforgeeks.org/print-leftmost-and-rightmost-nodes-of-a-binary-tree/
*/
// C/C++ program to print corner node at each level 
// of binary tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has key, pointer to left 
child and a pointer to right child */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

/* To create a newNode of tree and return pointer */
struct Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

/* Function to print corner node at each level */
void printCorner(Node *root) 
{ 
	// star node is for keeping track of levels 
	queue<Node *> q; 

	// pushing root node and star node 
	q.push(root); 
	q.push(NULL); 

	// if isFirst = true then left most node of that level 
	// will be printed 
	bool isFirst = false; 

	// if isOne = true then that level has only one node 
	bool isOne = false; 

	// last will store right most node of that level 
	int last; 

	// Do level order traversal of Binary Tree 
	while (!q.empty()) 
	{ 
		// dequeue the front node from the queue 
		Node *temp = q.front(); 
		q.pop(); 

		// if isFirst is true, then temp is leftmost node 
		if (isFirst) 
		{ 
			cout << temp->key << " "; 

			if (temp->left) 
				q.push(temp->left); 
			if (temp->right) 
				q.push(temp->right); 

			// make isFirst as false and one = 1 
			isFirst = false; 
			isOne = true; 
		} 

		// Else if temp is a separator between two levels 
		else if (temp == NULL) 
		{ 
			// Insert new separator if there are items in queue 
			if (q.size() >= 1) 
				q.push(NULL); 

			// making isFirst as true because next node will be 
			// leftmost node of that level 
			isFirst = true; 

			// printing last node, only if that level 
			// doesn't contain single node otherwise 
			// that single node will be printed twice			 
			if (!isOne) 
				cout << last << " "; 
		} 
		else
		{ 
			// Store current key as last 
			last = temp->key; 

			// Here we are making isOne = false to signify 
			// that level has more than one node 
			isOne = false; 
			if (temp->left) 
				q.push(temp->left); 
			if (temp->right) 
				q.push(temp->right); 
		} 
	} 
} 

// Driver program to test above function 
int main () 
{ 
	Node *root = newNode(15); 
	root->left = newNode(10); 
	root->right = newNode(20); 
	root->left->left = newNode(8); 
	root->left->right = newNode(12); 
	root->right->left = newNode(16); 
	root->right->right = newNode(25); 
	printCorner(root); 
	return 0; 
} 

