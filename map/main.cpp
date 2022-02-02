// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
#include "./avl_tree.hpp"
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

	// IF tree is right heavy
	// {
	//  IF tree's right subtree is left heavy
	//  {
	//  Perform Double Left rotation
	//  }
	//  ELSE
	//  {
	//  Perform Single Left rotation
	//  }
	// }
	// ELSE IF tree is left heavy
	// {
	//  IF tree's left subtree is right heavy
	//  {
	//  Perform Double Right rotation
	//  }
	//  ELSE
	//  {
	//  Perform Single Right rotation
	//  }
	// } 

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

void printBT(const std::string& prefix,  BstNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        std::cout << node->data << std::endl;
        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const std::string& prefix,  ft::BstNode<int>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        std::cout << node->data << std::endl;
        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}


int main()
{
	puts("************ft*************\n");
	ft::BstNode<int>* root = nullptr;
	ft::avl_tree<int, ft::BstNode<int> > av;

	root = av.insert(root,15);
	root = av.insert(root,10);
	root = av.insert(root,20);
	root = av.insert(root,25);
	root = av.insert(root,8);
	root = av.insert(root,12);

	printBT("", root, false);
	/* std::cout << "height of the tree : " << */
	std::cout << "Height : " << av.Height(root) << std::endl;
{
	puts("************std*************\n");
	BstNode* root = NULL;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

     printBT("", root, false);
	// int number;
	// cout<<"Enter number be searched\n";
	// cin>>number;
	// if(Search(root,number) == true) cout<<"Found\n";
	// else cout<<"Not Found\n";
}
}