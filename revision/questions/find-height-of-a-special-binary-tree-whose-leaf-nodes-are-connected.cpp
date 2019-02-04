/*
  https://www.geeksforgeeks.org/find-height-of-a-special-binary-tree-whose-leaf-nodes-are-connected/
  leafts form the circular list then
  r->r->l = r || r->l->r= r
*/
// C++ program to calculate height of a special tree 
// whose leaf nodes forms a circular doubly linked list 
#include <iostream> 
using namespace std; 

// A binary tree Node 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// function to check if given node is a leaf node or node 
bool isLeaf(Node* node) 
{ 
	// If given node's left's right is pointing to given node 
	// and its right's left is pointing to the node itself 
	// then it's a leaf 
	return node->left && node->left->right == node && 
		node->right && node->right->left == node; 
} 

/* Compute the height of a tree -- the number of 
Nodes along the longest path from the root node 
down to the farthest leaf node.*/
int maxDepth(Node* node) 
{ 
	// if node is NULL, return 0 
	if (node == NULL) 
		return 0; 

	// if node is a leaf node, return 1 
	if (isLeaf(node)) 
		return 1; 

	// compute the depth of each subtree and take maximum 
	return 1 + max(maxDepth(node->left), maxDepth(node->right)); 
} 

// Helper function that allocates a new tree node 
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 

// Driver code 
int main() 
{ 
	Node* root = newNode(1); 

	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->left->left->left = newNode(6); 

	// Given tree contains 3 leaf nodes 
	Node *L1 = root->left->left->left; 
	Node *L2 = root->left->right; 
	Node *L3 = root->right; 

	// create circular doubly linked list out of 
	// leaf nodes of the tree 

	// set next pointer of linked list 
	L1->right = L2, L2->right = L3, L3->right = L1; 

	// set prev pointer of linked list 
	L3->left = L2, L2->left = L1, L1->left = L3; 

	// calculate height of the tree 
	cout << "Height of tree is " << maxDepth(root); 

	return 0; 
} 

