// Student: Sean Dela Pena
// tree header file
//
//

#ifndef tree_hpp
#define tree_hpp

#include "node.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <iterator>

using namespace std;

class BST {

private:

	Node* root;
	string STACKBUFFER;

public:

	BST();
	~BST();
	
	Node* create(char data);
	Node* buildBST(string filename);
	Node* buildBST();
	string getWord(char data);
	string cleanBuffer();
	void insertBST(Node*& node, string data);
	void destroyTree(Node* leaf);
	void printPostorder(Node* node, int indent, ofstream& file);
	void printInorder(struct Node* node, int indent, ofstream &file);
	void printPreorder(struct Node* node, int indent, ofstream& file);

};

#endif


