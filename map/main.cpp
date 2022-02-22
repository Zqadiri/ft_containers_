// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
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

void printBT(const std::string& prefix,  ft::BstNode<ft::pair<int, std::string> >* node, bool isLeft)
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

void buildTree(ft::BstNode<ft::pair<int, std::string> >* root, int scrWidth, int itemWidth)
// breadth-first traversal with depth limit based on screen width and output field width for one elemet
{
	bool notFinished = false;
	// check the root
	if (root)
	{
		notFinished = true;
	}
	// calculate maximum possible depth
	int depth = 1;
	int field = scrWidth;
	while (field > itemWidth)
	{
		depth++;
		field /= 2;
	}
	// check result
	if (depth < 1)
	{
		cout << " -= erroneous output options =-" << endl;
		return;
	}
	ft::BstNode<ft::pair<int, std::string> >** pItems = new ft::BstNode<ft::pair<int, std::string> >*[1];
	*pItems = root; // pointer to item on the first level
	int itemCnt = 1;
	int divWidth = 1;
	// loop for output not more than depth levels until the data is not finished
	// where level is current depth of tree, and root is on the first level
	for (int level = 1; level <= depth && notFinished; level++)
	{
		itemCnt = (level == 1) ? 1 : (itemCnt * 2);
		divWidth *= 2;
		// make list of pointers to refer items on next level
		ft::BstNode<ft::pair<int, std::string> >** list = new ft::BstNode<ft::pair<int, std::string> >*[itemCnt * 2];
		// output all utems of that level
		int nextCnt = 0;
		notFinished = false;
		for (int i = 0; i < itemCnt; i++, nextCnt += 2)
		{
			int curWidth = (scrWidth / divWidth) * ((i > 0) ? 2 : 1);
			cout << setw((curWidth>=itemWidth) ? curWidth:(itemWidth/(1+(i==0))));
			if (pItems[i])
			{
				cout << pItems[i]->data.first << ":" << pItems[i]->data.second;
				list[nextCnt] = pItems[i]->left;
				list[nextCnt + 1] = pItems[i]->right;
				if (list[nextCnt] || list[nextCnt + 1])
					notFinished = true;
			}
			else
			{
				cout << "*";
				list[nextCnt] = NULL;
				list[nextCnt + 1] = NULL;
			}
		}
		cout << endl;
		// free the memory allocated for list of pointers
		if (pItems)
			delete[] pItems;
		pItems = list; // and shift to new one (for next level)
	}
	delete[] pItems;
}

void print_parent( ft::avl_tree<ft::pair<int, std::string> >::node_type* root)
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
	{
		ft::avl_tree<ft::pair<int, std::string> >::node_type* root = nullptr;
		ft::avl_tree<ft::pair<int, std::string> > av;
		int myints[] = {12, 82, 37, 64, 15};
		for (size_t i = 0; i < 0; ++i)
		{
		  	root = av.insert(root ,ft::make_pair(i,  "i"));
			std::cout << i << std::endl;
		}
		// printBT("", root, false);
		// print_parent(root);
	}

	{
		ft::map<std::string , std::string,  std::greater<std::string> > ft_m1;
		std::map<std::string, std::string, std::greater<std::string> > m2;
		ft::map<std::string , std::string,  std::greater<std::string> >::iterator it;
		std::map<std::string, std::string, std::greater<std::string> >::iterator it2;


		m2["γ"] = "gamma";
		m2["β"] = "beta";
		m2["α"] = "alpha";
		m2["γ"] = "gamma";

		for (it2 = m2.begin(); it2 != m2.end(); it2++)
			std::cout << it2->first << " => " << it2->second << '\n';

		ft_m1["γ"] = "gamma";
		ft_m1["β"] = "beta";
		ft_m1["α"] = "alpha";
		ft_m1["γ"] = "gamma";
	
		for (it = ft_m1.begin(); it != ft_m1.end(); ++it)
			std::cout << it->first << " --> " << it->second << '\n';

		// const ft::pair<std::string, std::string> &ft_ref = *(ft_m1.begin());
		// const ft::map<std::string, std::string, std::greater<std::string> >::iterator ft_iter = std::next(ft_m1.begin());

		// for (it = ft_m2.begin(); it != ft_m2.end(); ++it)
		//     std::cout << it->first << " => " << it->second << '\n';
	}
}

