/*
   keep track of expected node values and increase the length value.
*/
// C/C++ program to find longest consecutive 
// sequence in binary tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// A utility function to create a node 
Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Utility method to return length of longest 
// consecutive sequence of tree 
void longestConsecutiveUtil(Node* root, int curLength, 
							int expected, int& res) 
{ 
	if (root == NULL) 
		return; 

	// if root data has one more than its parent 
	// then increase current length 
	if (root->data == expected) 
		curLength++; 
	else
		curLength = 1; 

	// update the maximum by current length 
	res = max(res, curLength); 

	// recursively call left and right subtree with 
	// expected value 1 more than root data 
	longestConsecutiveUtil(root->left, curLength, 
						root->data + 1, res); 
	longestConsecutiveUtil(root->right, curLength, 
						root->data + 1, res); 
} 

// method returns length of longest consecutive 
// sequence rooted at node root 
int longestConsecutive(Node* root) 
{ 
	if (root == NULL) 
		return 0; 

	int res = 0; 

	// call utility method with current length 0 
	longestConsecutiveUtil(root, 0, root->data, res); 

	return res; 
} 

// Driver code to test above methods 
int main() 
{ 
	Node* root = newNode(6); 
	root->right = newNode(9); 
	root->right->left = newNode(7); 
	root->right->right = newNode(10); 
	root->right->right->right = newNode(11); 

	printf("%d\n", longestConsecutive(root)); 
	return 0; 
} 

