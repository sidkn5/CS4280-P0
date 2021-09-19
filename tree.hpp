//tree header file
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
	void insertBST(Node* &node, string data);
	Node* create(char data);
	Node* buildBST(string filename);
	string getWord(char data);
	string cleanBuffer();
	void destroyTree(Node* leaf);
	void printPostorder(Node* node);
	void printInorder(struct Node* node);
	void printPreorder(struct Node* node);

};

#endif


