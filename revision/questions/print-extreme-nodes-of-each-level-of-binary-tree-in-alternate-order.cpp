/*
  do level order traversal and print the left and right nodes alternate.
  https://www.geeksforgeeks.org/print-extreme-nodes-of-each-level-of-binary-tree-in-alternate-order/
*/
/* C++ program to print nodes of extreme corners 
of each level in alternate order */
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->right = node->left = NULL; 
	return node; 
} 

/* Function to print nodes of extreme corners 
of each level in alternate order */
void printExtremeNodes(Node* root) 
{ 
	if (root == NULL) 
		return; 

	// Create a queue and enqueue left and right 
	// children of root 
	queue<Node*> q; 
	q.push(root); 

	// flag to indicate whether leftmost node or 
	// the rightmost node has to be printed 
	bool flag = false; 
	while (!q.empty()) 
	{ 
		// nodeCount indicates number of nodes 
		// at current level. 
		int nodeCount = q.size(); 
		int n = nodeCount; 

		// Dequeue all nodes of current level 
		// and Enqueue all nodes of next level 
		while (n--) 
		{ 
			Node* curr = q.front(); 

			// Enqueue left child 
			if (curr->left) 
				q.push(curr->left); 

			// Enqueue right child 
			if (curr->right) 
				q.push(curr->right); 

			// Dequeue node 
			q.pop(); 

			// if flag is true, print leftmost node 
			if (flag && n == nodeCount - 1) 
				cout << curr->data << " "; 

			// if flag is false, print rightmost node 
			if (!flag && n == 0) 
				cout << curr->data << " "; 
		} 
		// invert flag for next level 
		flag = !flag; 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	// Binary Tree of Height 4 
	Node* root = newNode(1); 

	root->left = newNode(2); 
	root->right = newNode(3); 

	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(7); 

	root->left->left->left = newNode(8); 
	root->left->left->right = newNode(9); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(11); 
	root->right->right->left = newNode(14); 
	root->right->right->right = newNode(15); 

	root->left->left->left->left = newNode(16); 
	root->left->left->left->right = newNode(17); 
	root->right->right->right->right = newNode(31); 

	printExtremeNodes(root); 

	return 0; 
} 

