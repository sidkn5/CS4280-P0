// Student: Sean Dela Pena
// File: tree.c
//
//
// Sources: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//          https://www.cprogramming.com/tutorial/lesson18.html
//          https://www.geeksforgeeks.org/remove-duplicaterepeated-words-string/
//          https://www.geeksforgeeks.org/binary-tree-data-structure/
// Revised the traversals to fit the project description


#include "tree.hpp"
using namespace std;

BST::BST() {
    root = NULL;
    STACKBUFFER = "";
    return;
}

BST::~BST() {
    //destructor
}

//Builds the bst by the first alphanumeric char, and stores the words in a string buffer
//reads input from a file given
Node* BST::buildBST(string filename) {

    ifstream file;
    string word;
    string temp;
    
    Node* rootPtr = NULL;

    //open the file, iterate through all the words and insert to tree
    file.open(filename);
    if (file) {
        while (file >> word) {
            temp = word;     
            STACKBUFFER += word + ' ';      //buffer for the strings, contains all the words
            insertBST(root, word);          
        }
    }

    rootPtr = root;
    file.close();

    return rootPtr;
}

//Builds the bst by the first alphanumeric char, and stores the words in a string buffer
//same logic from above but reads input from keyboard
Node* BST::buildBST() {

    string userInput;
    Node* rootPtr = NULL;
    //read input until EOF (ctrl + d)
    while (cin >> userInput) {
        STACKBUFFER += userInput + ' ';
        insertBST(rootPtr, userInput);
    }
    
    return rootPtr;
}

//Create a new node
Node* BST::create(char data) {
    Node* temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

//inserts to the tree base of the first alphanumeric character
//if it already exists, don't make a new node
void BST::insertBST(Node* &root, string data) {
     
    if (root == NULL) {
        root = create(data[0]);
    }
    else if (root->data == data[0]) {
        //ignore it, the node for that letter already exists
    }
    else if(root->data > data[0]){
        insertBST(root->left, data);
    }
    else {
        insertBST(root->right, data);
    }
}

//removes the duplicates and inserts words in a hash, copy the hash to a string
string BST::cleanBuffer() {
    string noDupeBuffer;
    istringstream ss(STACKBUFFER);
    ostringstream stream;
    unordered_set<string> hsh;          //unique words will be inserted here

    //iterates through the words and insert unique words to the hash
    do{
        string word;
        ss >> word;
        while (hsh.find(word) == hsh.end()) {
            hsh.insert(word);
        }
    } while (ss);

    //copy the hash to a string and return that string
    copy(hsh.begin(), hsh.end(), ostream_iterator<string>(stream, " "));
    
    noDupeBuffer = stream.str();
    return noDupeBuffer;
}

//will return strings/words with that start with that letter/node
string BST::getWord(char data) {
    string temp = "";       //will hold the word being checked
    string group = "";      //will accumulate all the words that start with that letter
    
    string str = cleanBuffer();         //get the clean buffer with unique words
    istringstream iss(str);

    //go through the string and extract words that start with that letter
    while (iss >> temp) {
        if (data == temp[0]) {  
            //cout << "adding this word " << temp << endl;
                group += temp + ' ';
        }
    }

    return group;
}

//destroy the binary tree, free the pointers, point to null
void BST::destroyTree(Node* leaf)
{
    if (leaf != NULL)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
        leaf = NULL;
    }
}

//Given a binary tree, print its nodes in inorder
//indents/levels are in tabs, root (no tab), level 1 (1 tab), level 2 (2tabs) ...
//tree will be printed in a horizontal orientation
void BST::printInorder(struct Node* node, int indent, ofstream &file)
{
    string word = "";

    if (node == NULL) {
        return;
    }

    // first recur on left child 
    printInorder(node->left, indent + 1, file);
  
    // print out the node to their respective output files
    //gets the words that start with that letter
    word = getWord(node->data);
    //file << "Level " << indent << "\t";
    for (int i = 0; i < indent; i++) {
        file << "\t";
    }
    
    file << node->data << ": " << word << " " << endl;
   
    // now recur on right child 
    printInorder(node->right, indent + 1, file);
   
}

//Given a binary tree, print its nodes in postorder
//indents/levels are in tabs, root (no tab), level 1 (1 tab), level 2 (2tabs) ...
void BST::printPostorder(Node* node, int indent, ofstream& file)
{
    string word = "";

    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left, indent+1, file);

    // then recur on right subtree
    printPostorder(node->right, indent+1, file);

    // print out the node to their respective output files
    //gets the words that start with that letter
    word = getWord(node->data);
    //file << "Level " << indent << "\t";
    for (int i = 0; i < indent; i++) {
        file << "\t";
    }
    
    file << node->data << ": " << word << " " << endl;

}

// Given a binary tree, print its nodes in preorder
//indents/levels are in tabs, root (no tab), level 1 (1 tab), level 2 (2tabs) ...
void BST::printPreorder(struct Node* node, int indent, ofstream& file)
{
    string word = "";

    if (node == NULL)
        return;

    // print out the node to their respective output files
    //gets the words that start with that letter
    word = getWord(node->data);
    //file << "Level " << indent << "\t";
    for (int i = 0; i < indent; i++) {
        file << "\t";
    }
  
    file << node->data << ": " << word << " " << endl;

    // then recur on left sutree 
    printPreorder(node->left, indent + 1, file);

    // now recur on right subtree 
    printPreorder(node->right, indent + 1, file);
}
