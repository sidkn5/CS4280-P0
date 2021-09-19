//Node.h header file
//
//

#ifndef node_h
#define node_h
#include <cstddef>

struct Node {
	char data;
	Node* left;
	Node* right;
	Node* parent;
	
	/*Node(char val) {
		data = val;
		left = NULL;
		right = NULL;
		parent = NULL;
	}*/
};


#endif