/*Student: Sean Dela Pena 
 *Assignment P0 - practice with standards, trees, traversals,
 *	 command line argumets and file IO.
 *	This program creates a binary tree base on the first alphanumerical character,
 *	then prints by the three different traversals.
 *Professor: Mark Hauschild
 *Class: CS 4280
 *Date: 9-19-21
 */

//#include <iostream>
//#include <fstream>
#include "tree.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	BST tree;							//BST class in tree.cpp
	ifstream file;
	string filename = "output";			//defaults to output if keyboard input is used
	Node* rootPtr = NULL;
	int indent = 0;						//used for printing the "levels" of the tree 
	
	//process command line arguments
	if (argc == 1) {
		//no arguments entered, will read from keyboard
		//build bst given keyboard inputs
		rootPtr = tree.buildBST();
	}
	if (argc == 2) {

		//filename given, P0 somefile invocation
		//check if filename exists
		filename = argv[1];		
		file.open(filename);
		if (file) {
			cout << "Opening and working with the file..." << endl;
		}
		else {
			cout << "File does not exist! Terminating..." << endl;
			exit(0);
		}
		file.close();

		//build bst given a filename
		rootPtr = tree.buildBST(filename);
	}
	if (argc > 2) {
		//P0 < somefile invocation
		rootPtr = tree.buildBST();
	}

	//output files with respect to the traversals
	ofstream preOrderFile(filename + ".preorder", ios::out);
	ofstream inOrderFile(filename + ".inorder", ios::out);
	ofstream postOrderFile(filename + ".postorder", ios::out);


	//print to the output files made above
	cout << "Printing the traversals in their respective files... " << endl;
	tree.printInorder(rootPtr, indent, inOrderFile);
	tree.printPostorder(rootPtr, indent, postOrderFile);
	tree.printPreorder(rootPtr, indent, preOrderFile);
	cout << "ls, to see the files made, make clean to delete the files..." << endl;

	//close the files
	file.close();
	preOrderFile.close();
	inOrderFile.close();
	postOrderFile.close();

	//free the ptrs and point to null
	tree.destroyTree(rootPtr);

	return 0;
}
