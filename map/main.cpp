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

void printBT(const std::string& prefix,  ft::BstNode<ft::pair<key_t, int> >* node, bool isLeft)
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

void buildTree(ft::BstNode<ft::pair<key_t, int> >* root, int scrWidth, int itemWidth)
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
    ft::BstNode<ft::pair<key_t, int> >** pItems = new ft::BstNode<ft::pair<key_t, int> >*[1];
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
        ft::BstNode<ft::pair<key_t, int> >** list = new ft::BstNode<ft::pair<key_t, int> >*[itemCnt * 2];
        // output all utems of that level
        int nextCnt = 0;
        notFinished = false;
        for (int i = 0; i < itemCnt; i++, nextCnt += 2)
        {
            int curWidth = (scrWidth / divWidth) * ((i > 0) ? 2 : 1);
            cout << setw((curWidth>=itemWidth) ? curWidth:(itemWidth/(1+(i==0))));
            if (pItems[i])
            {
                cout << pItems[i]->data._first << ":" << pItems[i]->data._second;
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

void print_parent( ft::avl_tree<ft::pair<int, int> >::node_type* root)
{
    if (root->left != NULL)
        print_parent(root->left);
    if (root->right != NULL)
        print_parent(root->right);
    if (root->rootPtr != NULL)
        std::cout << "parent of " << root->data._first << " is : " << root->rootPtr->data._first << std::endl;
    else
        std::cout << "node " << root->data._first << " is root of the tree" << std::endl;
}


// //? https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

int main()
{
    {
        ft::pair<int, int> p(10, 100);
        ft::pair<int, int> q(11, 101);
        ft::pair<int, int> e(12, 102);
        ft::pair<int, int> t(15, 105);
        ft::pair<int, int> y(16, 106);
        ft::pair<int, int> u(17, 107);

        ft::avl_tree<ft::pair<int, int> >::node_type* root = nullptr;
    	ft::avl_tree<ft::pair<int, int> > av;

    	root = av.insert(root, p);
    	root = av.insert(root, q);
    	root = av.insert(root, e);
    	root = av.insert(root, t);
    	root = av.insert(root, y);
    	root = av.insert(root, u);
    	buildTree(root, 80, 10);
        print_parent(root);
        // return (0);
    }
	puts("\n************************\n");

	ft::avl_tree<ft::pair<key_t,int> > av;
	ft::map<key_t, int>::iterator it, it_end;
	ft::map<key_t, int> mp;

	mp.insert(ft::pair<key_t, int>(10, 100));
	mp.insert(ft::pair<key_t, int>(11, 101));
	mp.insert(ft::pair<key_t, int>(12, 102));
	mp.insert(ft::pair<key_t, int>(15, 105));
	mp.insert(ft::pair<key_t, int>(16, 106));
	mp.insert(ft::pair<key_t, int>(17, 107));
    it = mp.upper_bound(11);
    // it_end = mp.end();
    std::cout << "-> "<< it->_first << " => " << it->_second << '\n';
    // for ( ; it != it_end; ++it){
    // 	std::cout << it->_first << " => " << it->_second << '\n';
    // }
    // std::cout << "-> "<< it_end->_first << " => " << it_end->_second << '\n';
	{
		std::cout << "\n----- std -----" << std::endl;
		std::map<key_t, int> map;
		map.insert(std::pair<key_t,int>(10, 100));
		map.insert(std::pair<key_t,int>(11, 101));
		map.insert(std::pair<key_t,int>(12, 102));
		map.insert(std::pair<key_t,int>(15, 105));
		map.insert(std::pair<key_t,int>(16, 106));
		map.insert(std::pair<key_t,int>(17, 107));
		std::map<key_t, int>::iterator it = map.upper_bound(16);
		std::cout << " bound ::" << it->first << std::endl;
		for ( ; it!=map.end(); ++it)
    		std::cout << it->first << " => " << it->second << '\n';
	}
}

