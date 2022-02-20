/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/20 17:04:39 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_
#define AVL_TREE_

#include "../utilities/utility.hpp"
#include <iostream>
#include <sys/types.h>
#include <functional>
#include <memory>
#include <iomanip>

using namespace std;
namespace ft
{
	// The keyword typename was introduced to specify that the identifier that follows is a type. 
	template <typename T,typename Compare = std::less<typename T::first_type>,
	typename pairAllocator = std::allocator<T> > 
	
	class avl_tree
	{
		public:
			typedef 	typename 	T::first_type			key_type;
			typedef 	typename 	T::second_type			mapped_type;
			typedef					T						value_type;
			typedef					ft::BstNode<T>			node_type;
			typedef					pairAllocator			pair_alloc;
			typedef					Compare					compare;

		avl_tree(){
			// puts("in");
			rootPtr = nodeAlloc.allocate(1);
			rootPtr->right = rootPtr->left = nullptr;
			rootPtr = nullptr;
			treeSize = 0;
			// rootPtr->Height = 0;
		};

		avl_tree(const avl_tree &tree){
			*this = tree;
		}

		avl_tree &operator=(const avl_tree &tree){
			this->treeSize = tree.treeSize;
			this->nodeAlloc = tree.nodeAlloc;
			this->pairAlloc = tree.pairAlloc;
			this->rootPtr = tree.rootPtr;
			return *this;
		}

		bool operator!=(const avl_tree &rhs)const {
			return (rootPtr != rhs.rootPtr);
		}

		~avl_tree(){};

		node_type*		beginTree( node_type *root){
			node_type *current = root;
			while (current->left != nullptr)
				current = current->left;
			return current;
		}

		bool		isEmpty(){
			return (rootPtr == nullptr);
		}

		int calheight(node_type *p){
			if(p->left && p->right){
			if (p->left->Height < p->right->Height)
				return p->right->Height + 1;
			else return  p->left->Height + 1;
			}
			else if(p->left && p->right == NULL){
			   return p->left->Height + 1;
			}
			else if(p->left ==NULL && p->right){
			   return p->right->Height + 1;
			}
			return 0;
		}

		node_type*		leftLeftRotation(node_type *root) //? rotate the rootPtr too 
		{
			std::cout << "leftLeftRotation" << std::endl;
			node_type *new_parent = root->left;
			root->left = new_parent->right;
			new_parent->right = root;

			new_parent->rootPtr = root->rootPtr;
			root->rootPtr = new_parent; 
			return new_parent;
		}

		node_type*		rightRightRotation(node_type *root)
		{
			std::cout << "RightRightRotation" << std::endl;
			node_type *new_parent = root->right;
			
			root->right = new_parent->left;
			new_parent->left = root;
			if (root->right != nullptr)
				root->right->rootPtr  = new_parent->left; //!
			new_parent->rootPtr = root->rootPtr;
			root->rootPtr = new_parent;
			
			return new_parent;
		}

		node_type*		leftRightRotation(node_type *root)
		{
			std::cout << "leftRightRotation" << std::endl;
			node_type *new_parent;

			new_parent = root->left;
			root->left = rightRightRotation(new_parent);
			return leftLeftRotation(root);
		}
		
		node_type*		rightLeftRotation(node_type *root)
		{
			std::cout << "rightLeftRotation" << std::endl;
			node_type *new_parent;

			new_parent = root->right;
			root->right = leftLeftRotation(new_parent);
			return rightRightRotation(root);
		}

		node_type*		balanceTree(node_type *root)
		{
			// int	BalanceFactor = Height(root->left) - Height(root->right);
			//? IF tree is LEFT heavy
			if (difference(root) > 1)
			{
				if (difference(root->left) > 0)
					root = leftLeftRotation(root); // ? ll rotation if the tree is left heavy && the ST is left heavy 
				else
					root = leftRightRotation(root); //? lr Rottion if the tree is left heavy && ST is right heavy				
			}
			//? ELSE IF tree is RIGHT heavy
			else if (difference(root) < -1)
			{
				if (difference(root->right) > 0)
					root = rightLeftRotation(root); //? Right Left
				else 
					root = rightRightRotation(root); //? Right Right
			}
			return root;
		}
		
		bool			searchForKey(const key_type key, node_type* root)
		{
			if (root == nullptr) // * rearch the end of the tree
				return false;
			else if (root->data.first == key)
				return true;
			else if (key <= root->data.first)
				return searchForKey(key, root->left);
			else
				return searchForKey(key, root->right);
		}

		node_type*		searchKey(const key_type key, node_type* root)
		{
			if (root == nullptr) // * rearch the end of the tree
				return root;
			else if (root->data.first == key)
				return root;
			else if (key <= root->data.first)
				return searchKey(key, root->left);
			else
				return searchKey(key, root->right);
		}

		// int difference(node_type *root)
		// {
		// 	return (Height(root->left) - Height(root->right));
		// 	// return (root->leftH - root->rightH);
		// }

		int difference(node_type *root)
		{
			if(root->left && root->right){
				return root->left->Height - root->right->Height; 
			}
			else if(root->left && root->right == NULL){
				return root->left->Height; 
			}
			else if(root->left== NULL && root->right ){
				return -root->right->Height;
			}
		}

		
		node_type*		newNode(const value_type &val){
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			nodeAlloc.construct(newNode, ft::make_pair(val.first, val.second));
			treeSize++;
			newNode->Height = 0;
			return newNode;
		}
		
		node_type*		insert(node_type *root, const value_type &val) //! loop infinie
		{
			if (root == nullptr){
				root = newNode(val);
				root->rootPtr = nullptr;
				return (root);
			}
			if (!searchForKey(val.first, root))
			{
				if (val.first < root->data.first)
				{
					node_type *lchild = insert(root->left, val);
					root->left  = lchild;
					lchild->rootPtr = root;
				}
				else if (val.first > root->data.first)//! switch to compare Compare(key, root->data._first)
				{
					node_type *rchild = insert(root->right, val);
					root->right  = rchild;
					rchild->rootPtr = root;
				}
				root->Height = calheight(root);
				root = balanceTree(root);
			} //! search if tha key exists or not
			return (root);
		}

		node_type*		minValue(node_type *root)
		{
			node_type *current = root;
			while (current->right != nullptr)
				current = current->right;
			return current;
		}

		node_type*		deleteNode(node_type *root,const key_type key)
		{
			if (root == nullptr)
				return nullptr;
			else if (key < root->data.first)
				root->left = deleteNode(root->left, key);
			else if (key > root->data.first)
				root->right = deleteNode(root->right, key);
			else if (key == root->data.first)	//! delete the root cases (root wit no child, one child, x childs)
			{
				if (root->left == nullptr)
				{
					node_type *new_parent = root->right;
					nodeAlloc.destroy(root);
					return new_parent;
				}
				else if (root->right == nullptr)
				{
					node_type *new_parent = root->left;
					nodeAlloc.destroy(root);
					return new_parent;
				}
				else
				{
					// std::cout << root->data.first << std::endl;
					node_type *ret = minValue(root->left);
					nodeAlloc.destroy(root);
					nodeAlloc.construct(root, ft::make_pair(ret->data.first, ret->data.second));
					root->left = deleteNode(root->left, ret->data.first);
				}
			}
			return root;		
		}

		public:
			typename pairAllocator::template rebind<node_type>::other nodeAlloc;
			compare		comp;
			node_type	*rootPtr;
			pair_alloc	pairAlloc;
			size_t		treeSize;
	};
}

// https://stackoverflow.com/questions/57206516/how-standard-containers-allocates-memory-for-their-nodes-internal-structures
// https://stackoverflow.com/questions/37284243/why-can-stdlist-have-an-allocator-of-type-t

#endif