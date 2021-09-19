/*Sean Dela Pena 
 *P0 - practice with standards, trees, traversals
 *	 command line argumets and file IO.
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include "tree.hpp"

using namespace std;


int main(int argc, char* argv[]) {

	BST tree;			//BST class in tree.cpp
	ifstream file;
	string filename;
	Node* rootPtr = NULL;
	
	//still needs testing
	//process command line arguments
	if (argc == 1) {
		//no arguments entered, will read from keyboard
		filename = "tempFilename";
		//cout << filename << endl;
	}
	if (argc == 2) {
		//check if filename exists
		filename = argv[1];		
		file.open(filename);
		if (file) {
			cout << "Opening and working with the file..." << endl;
		}
		else {
			cout << "File does not exist! Terminating." << endl;
			exit(0);
		}
		file.close();
	}
	if (argc > 2) {
		filename = "tempFilename";
		cout << "Please refer to help for proper use of the program." << endl;
	}

	
	
	//building BSTs
	rootPtr = tree.buildBST(filename);


	//output files with respect to the traversals
	ofstream preOrderFile(filename + ".preorder", ios::out);
	ofstream inOrderFile(filename + ".inorder", ios::out);
	ofstream postOrderFile(filename + ".postorder", ios::out);


	//test print
	//tree.printInorder(rootPtr);
	tree.printPostorder(rootPtr);

	//close the files
	file.close();
	preOrderFile.close();
	inOrderFile.close();
	postOrderFile.close();

	return 0;
}
