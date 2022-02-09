// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
#include "./avl_tree.hpp"
#include "../utilities/bidirectional_iterator.hpp"
#include <string.h>
#include <iomanip>
#include <map>
#include "Map.hpp"

using namespace std;
//Definition of Node for Binary search tree
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

void printBT(const std::string& prefix,  ft::BstNode<key_t, int>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        std::cout << node->data._second << std::endl;
        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void buildTree(ft::BstNode<key_t, int>* root, int scrWidth, int itemWidth)
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
    ft::BstNode<key_t, int>** pItems = new ft::BstNode<key_t, int>*[1];
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
        ft::BstNode<key_t, int>** list = new ft::BstNode<key_t, int>*[itemCnt * 2];
        // output all utems of that level
        int nextCnt = 0;
        notFinished = false;
        for (int i = 0; i < itemCnt; i++, nextCnt += 2)
        {
            int curWidth = (scrWidth / divWidth) * ((i > 0) ? 2 : 1);
            cout << setw((curWidth>=itemWidth) ? curWidth:(itemWidth/(1+(i==0))));
            if (pItems[i])
            {
                cout << pItems[i]->data._first; //<< ":" << pItems[i]->data._second;
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

// //? https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

int main()
{
	puts("************Left Heavy************\n");
	ft::BstNode<key_t, int>* root = nullptr;
	ft::avl_tree<key_t, int, ft::BstNode<key_t, int> > av;

	// ft::map_iterator<ft::BstNode<key_t, int>, ft::avl_tree<key_t, int, ft::BstNode<key_t, int> > > it;
	ft::map<key_t, int> it;

	std::map<key_t, int>::iterator std_it;
	// it = 
	root = av.insert(root,50, 100);
	root = av.insert(root,51, 70);
	root = av.insert(root,5 , 40);
	root = av.insert(root,59 ,194);
	root = av.insert(root,48 ,195);
	root = av.insert(root,71 ,90);

	buildTree(root, 80, 10);
	std::cout << std::endl;

	it.begin();
	// std::cout << it << std::endl;
	// root = av.deleteNode(root, 50);
	std::cout << std::endl;
	buildTree(root, 80, 10);

	// root = av.deleteNode(root, 194);
	// buildTree(root, 80, 5);


	// root = av.deleteNode(root, 12);
	// printBT("", root, false);


	// {

	// 	ft::BstNode<key_t, int>* root = nullptr;
	// 	ft::avl_tree<int, ft::BstNode<key_t, int> > av;

	// 	root = av.insert(root,20);
	// 	root = av.insert(root,10);
	// 	root = av.insert(root,23);
	// 	root = av.insert(root,24);
	// 	root = av.insert(root,21);
	// 	root = av.insert(root,22);
	// 	// root = av.insert(root,12);

	// 	printBT("", root, false);
	// 	av.Height(root) ;
	// }
	// puts("************Right Heavy************\n");

// {
	// puts("************std*************\n");
	// BstNode* root = NULL;
	// root = Insert(root,15);
	// root = Insert(root,10);
	// root = Insert(root,20);
	// root = Insert(root,25);
	// root = Insert(root,8);
	// root = Insert(root,12);

    //  printBT("", root, false);
	// int number;
	// cout<<"Enter number be searched\n";
	// cin>>number;
	// if(Search(root,number) == true) cout<<"Found\n";
	// else cout<<"Not Found\n";
// }
	// {
   	// 	char s[]="Hello World!";
   	// 	int Uppercase = 0; //modified by the lambda
   	// 	for_each(s, s+sizeof(s), [&Uppercase] (char c)
	// 	{
   	// 		if (isupper(c))
   	// 		 Uppercase++;
   	// 	});
 	// 	cout<< Uppercase<<" uppercase letters in: "<< s<<endl;
	}
// }