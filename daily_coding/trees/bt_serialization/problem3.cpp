/*
 * Programmer: Renato Francia
 * Program: Binary tree Serialization
 */
#include <iostream>
#include <fstream>

#define MARKER -1;

using namespace std;

// Declaration of Tree Node
// Making it public for now until I rehash how to make it private and using
// Getters and setters for clean rehash
class Node {
	public:
	  int value;
		Node* left;
		Node* right;
};

/*
 * Helper function to allocate a new node with value and NULL (left/right) nodes
 */
Node* newNode(int value) {
	Node* temp 	= new Node;
	temp->value 	= value;
	temp->left 	= NULL;
	temp->right = NULL;

	return (temp);
}

/*
 * Store tree in a file pointed
 */
void serialize(Node* root) {

	fstream fs;
	fs.open("bt.txt", fstream::in | fstream::out | fstream::app);

	// If null just print NULL
	if(root == NULL){
		fs << MARKER;
		return;
	}

	// else store the value with it's children
	// Using recursion with preording parsing
	fs << root->value;
	serialize(root->left);
	serialize(root->right);

	fs.close();
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(9);

	serialize(root);

	return 0;
}

