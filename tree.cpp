//File: tree.c
//
//
//Sources: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//        https://www.cprogramming.com/tutorial/lesson18.html
//Revised the traversals to fit the project description


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
Node* BST::buildBST(string filename) {

    ifstream file;
    int count = 0;
    string word;
    string temp;
    string stackBuffer = "";
    string nodeBuffer = "";
    //string bufferWords;
    
    Node* rootPtr = NULL;

    //open the file and count the words
    file.open(filename);
    if (file) {
        while (file >> word) {
            temp = word;     
            STACKBUFFER += word + ' ';      //buffer for the strings
            nodeBuffer += word[0];          //buffer for the nodes //not needed
            insertBST(root, word);
            count++;
            
        }
    }

    rootPtr = root;
    file.close();
    cout << "StackedBuffer: " << STACKBUFFER << endl;

    return rootPtr;
    //exit(0);
}

//Create a new node, root
Node* BST::create(char data) {
    Node* temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

void BST::insertBST(Node* &root, string data) {
    
    /*for (int i = 0; i < nodeBuffer.size(); i++) {
        if (data[0] == i) {
            //ignore it, it already exists
        }
        else {
            if (root == NULL) {
                root = create(data[0]);
            }
            else if (root->data > data[0]) {
                insertBST(root->left, data);
            }
            else {
                insertBST(root->right, data);
            }
        }
    }*/
    
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
    unordered_set<string> hsh;

    do{
        string word;
        ss >> word;
        while (hsh.find(word) == hsh.end()) {
            hsh.insert(word);
        }
    } while (ss);
    copy(hsh.begin(), hsh.end(), ostream_iterator<string>(stream, " "));
    
    noDupeBuffer = stream.str();
    return noDupeBuffer;
}

//will return strings/words with that start with that letter/node
string BST::getWord(char data) {
    string temp = "";       //will hold the word being checked
    string group = "";      //will accumulate all the words that start with that letter
    //istringstream iss(STACKBUFFER);
    
    string str = cleanBuffer();
    istringstream iss(str);

    //go through the string and extract words that start with that letter
    while (iss) {
        iss >> temp;
        if (data == temp[0]) {  
                group += temp + ' ';        
        }
    }

    return group;
}

//destroy the binary tree and free the pointers
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
void BST::printInorder(struct Node* node)
{
    string word = "";
    
    //cout << node->data << endl;
    if (node == NULL) {
        return;
    }

    // first recur on left child 
    printInorder(node->left);
  
    // print out the node to their respective output files
    //cout << node->data << " ";
    word = getWord(node->data);
    cout << word << " ";
   
    // now recur on right child 
    printInorder(node->right);
   
}


void BST::printPostorder(Node* node)
{
    string word = "";

    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // print out the node to their respective output files
    //cout << node->data << " ";
    word = getWord(node->data);
    cout << word << " ";
}



// Given a binary tree, print its nodes in preorder
void BST::printPreorder(struct Node* node)
{
    string word = "";
    if (node == NULL)
        return;

    // print out the node to their respective output files
    word = getWord(node->data);
    cout << word << " ";

    // then recur on left sutree 
    printPreorder(node->left);

    // now recur on right subtree 
    printPreorder(node->right);
}
