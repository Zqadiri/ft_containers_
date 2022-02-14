/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/14 19:38:50 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_
#define AVL_TREE_

#include "../utilities/utility.hpp"
#include <iostream>
#include <sys/types.h>
#include <functional>
#include <memory>

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
			rootPtr = nodeAlloc.allocate(1);
			rootPtr->right = rootPtr->left = nullptr;
			treeSize = 0;
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
		
		~avl_tree(){
			// free the allocated space
		};

		node_type*		beginTree(node_type *root)
		{
			std::cout << treeSize << std::endl;
			// if (this->treeSize == 1)
			// 	return(root);
			node_type *current = root;
			while (current->left != nullptr)
				current = current->left;
			// std::cout << "begin : " <<"{{" << current->data._first << "}" << std::endl;
			return current;
		}
		
		bool		isEmpty()
		{
			return (rootPtr == nullptr);

			// 	return true;
			// return false;
		}



		int		Height(node_type *root)
		{
			int height = 0;

			if (root == nullptr)
				return -1;
			if (root != nullptr)
			{
				int leftHeight = Height(root->left);
				int rightHeight = Height(root->right);
				int max_height = std::max(leftHeight, rightHeight);
				height = max_height + 1;
				// printf (" | %d {%d,%d}, (%d,%d)", height, root->data, root->data,
				// leftHeight, rightHeight);
			}
			return height;
		}

		int difference(node_type *root)
		{
			int l_height = Height(root->left);
			int r_height = Height(root->right);
			int b_factor = l_height - r_height;
			return b_factor;
		}

		node_type*		leftLeftRotation(node_type *root)
		{
			std::cout << "leftLeftRotation" << std::endl;
			node_type *new_parent = root->left;
			node_type *tmp = new_parent->right;

			new_parent->right = root;
			root->left = tmp;
			return new_parent;
		}
		
		node_type*		rightRightRotation(node_type *root)
		{
			std::cout << "rightRightRotation" << std::endl;
			node_type *new_parent = root->right;
			node_type *tmp = new_parent->left;

			new_parent->left = root;
			root->right = tmp;
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
			int	BalanceFactor = Height(root->left) - Height(root->right);
			std::cout << "\nBL: " << BalanceFactor << std::endl;
			//? IF tree is LEFT heavy
			if (BalanceFactor > 1)
			{
				std::cout << "LEFT heavy : ";
				std::cout << "L " << difference(root->left) << std::endl << std::endl;
				if (difference(root->left) > 0)
					root = leftLeftRotation(root); // ? ll rotation if the tree is left heavy && the ST is left heavy 
				else
					root = leftRightRotation(root); //? lr Rottion if the tree is left heavy && ST is right heavy				
			}
			//? ELSE IF tree is RIGHT heavy
			else if (BalanceFactor < -1)
			{
				std::cout << "Right heavy : ";
				std::cout << "L " << difference(root->right)  << std::endl<< std::endl;
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
			else if (root->data._first == key)
				return true;
			else if (key <= root->data._first)
				return searchForKey(key, root->left);
			else
				return searchForKey(key, root->right);
		}
		
		node_type*		newNode(const value_type &val)
		{
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			nodeAlloc.construct(newNode, ft::make_pair(val._first, val._second));
			treeSize++;
			std::cout << "[treeSize] " << treeSize << std::endl;
			return newNode;
		}
		
		//?  Perform Rotation
		node_type*		insert(node_type *root, const value_type &val)
		{
			// std::cout << val._first  << std::endl;
			key_type key = val._first;
			key_type value = val._second;
			if (treeSize == 0){
				rootPtr = root = newNode(val);
				std::cout << "ptr: " << rootPtr->data._first << std::endl;
				std::cout << "Value inserted successfully" << std::endl;
				return (root);
			}
			if (!searchForKey(key, root))
			{
				if (key < root->data._first)
				{
					root->left = insert(root->left,val);
					root = balanceTree(root);
				}
				else if (key > root->data._first) //! switch to compare Compare(key, root->data._first)
				{
					root->right = insert(root->right,val);
					root = balanceTree(root);
				}
			} //! search if tha key exists or not
			rootPtr = root;
			return root;
		}

		// node_type*		minValue(node_type *root)
		// {
		// 	node_type *current = root;
		// 	if (current->right != nullptr)
		// 	{
		// 		while (current->right != nullptr)
		// 			current = current->right;
		// 	}
		// 	// std::cout << "minValue : " <<"[" << current->data._first << "]" << std::endl;
		// 	return current;
		// }

		// node_type*		deleteNode(node_type *root,const key_type key)
		// {
		// 	if (root == nullptr)
		// 		return nullptr;
		// 	else if (key < root->data._first)
		// 	{
		// 		root->left = deleteNode(root->left, key);
		// 		// std::cout << "Left"  << std::endl;
		// 	}
		// 	else if (key > root->data._first)
		// 	{
		// 		root->right = deleteNode(root->right, key);
		// 		// std::cout << "Right" << std::endl;
		// 	}
		// 	else if (key == root->data._first)	//! delete the root cases (root wit no child, one child, x childs)
		// 	{
		// 		if (root->left == nullptr)
		// 		{
		// 			node_type *new_parent = root->right;
		// 			nodeAlloc.destroy(root);
		// 			return new_parent;
		// 		}
		// 		else if (root->right == nullptr)
		// 		{
		// 			node_type *new_parent = root->left;
		// 			nodeAlloc.destroy(root);
		// 			return new_parent;
		// 		}
		// 		else
		// 		{
		// 			node_type *ret = minValue(root->left);
		// 			// std::cout << "ret : "<< ret->data._first << std::endl;
		// 			root->data = ret->data;
		// 			root->left = deleteNode(root->left, ret->data._first);
		// 		}
		// 	}
		// 	return root;		
		// }
		
		// private:
			// typename _A::template rebind<_Ty>::other 
			// using nodeAlloc = typename pairAllocator::template rebind<Node>::other;
		public:
			typename pairAllocator::template rebind<node_type>::other nodeAlloc;
			node_type	*rootPtr;
			pair_alloc	pairAlloc;
			size_t		treeSize;
	};
}

// https://stackoverflow.com/questions/57206516/how-standard-containers-allocates-memory-for-their-nodes-internal-structures
// https://stackoverflow.com/questions/37284243/why-can-stdlist-have-an-allocator-of-type-t

#endif