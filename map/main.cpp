// Simple program to create a BST of integers and search an element in it 
// Binary Search Tree - Implemenation in C++
#include <iostream>
#include "./avl_tree.hpp"
#include "../utilities/utility.hpp"
#include <string.h>
#include <iomanip>
#include <map>
#include "Map.hpp"

using namespace std;
// //Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

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

bool Search(BstNode* root,int data)
{
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

void printBT(const std::string& prefix,  ft::avl_tree<ft::pair<int, std::string> >::node_type* node, bool isLeft)
{
	if( node != nullptr )
	{
		std::cout << prefix;
		std::cout << (isLeft ? "├──" : "└──" );
		// print the value of the node
		std::cout << node->data.first << std::endl;
		// enter the next tree level - left and right branch
		printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
		printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}


void print_parent( ft::avl_tree<ft::pair<int , std::string> >::node_type* root)
{
	if (root->left != NULL)
		print_parent(root->left);
	if (root->right != NULL)
		print_parent(root->right);
	if (root->rootPtr != NULL)
		std::cout << "parent of " << root->data.first << " is : " << root->rootPtr->data.first << "  "<< root->Height  << std::endl;
	else
		std::cout << "node " << root->data.first << " is root of the tree" << ":" << root->Height << std::endl;
}


// //? https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

int main()
{
	/*{
		ft::avl_tree<ft::pair<int , std::string > >::node_type* root = nullptr;
		ft::avl_tree<ft::pair<int , std::string > > av;
		int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150};
		for (size_t i = 0; i < 9; ++i)
		  	root = av.insert(root ,ft::make_pair(arr[i],  "i"));
		for (size_t i = 0; i < 1; ++i){
		  	  	root = av.insert(root ,ft::make_pair(i,  "i"));
				printBT("", root, false);
				print_parent(root);
		}
		for (size_t i = 0; i < 1 ; ++i){
			root = av.deleteNode(root , 0);
			printBT("", root, false);
		}
	}*/

		ft::map<int , std::string > m1;
		ft::map<int, std::string > m2;
		ft::map<int, std::string >::iterator it;
            
		for (size_t i = 0; i < 20; ++i)
		  	m1.insert(ft::make_pair<int, std::string>(i,  "i"));
		for (size_t i = 0; i < 10; ++i)
		  	m2.insert(ft::make_pair<int, std::string>(i,  "i"));
		std::cout << "rhs = " << m1.size() << " lhs = " << m2.size() << std::endl;
		m1 = m2;
		std::cout << "rhs = " << m1.size() << " lhs = " << m2.size() << std::endl;
		for (it = m1.begin(); it != m1.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

}

