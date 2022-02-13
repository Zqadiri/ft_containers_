/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/13 18:10:30 by zqadiri          ###   ########.fr       */
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
	template <typename Key, typename T,typename Compare = std::less<Key>, typename Node = ft::BstNode<Key, T>,
	typename pairAllocator = std::allocator<ft::pair<Key, T> > >
	
	class avl_tree
	{
		public:
			typedef		Node				node_type;
			typedef		pairAllocator		pair_alloc;
			typedef		Compare				compare;

		avl_tree(){
			treeSize = 0;
			rootPtr = nullptr;
		};
		
		~avl_tree(){
			// free the allocated space
		};

		bool		isEmpty()
		{
			if (rootPtr == nullptr)
				return true;
			return false;
		}

		node_type*		newNode(const Key key, const T value)
		{
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			nodeAlloc.construct(newNode, ft::make_pair(key, value));
			treeSize++;
			return newNode;
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
			// std::cout << "\nBL: " << BalanceFactor << std::endl;
			//? IF tree is LEFT heavy
			if (BalanceFactor > 1)
			{
				// std::cout << "LEFT heavy : ";
				// std::cout << "L " << difference(root->left) << std::endl << std::endl;
				if (difference(root->left) > 0)
					root = leftLeftRotation(root); // ? ll rotation if the tree is left heavy && the ST is left heavy 
				else
					root = leftRightRotation(root); //? lr Rottion if the tree is left heavy && ST is right heavy				
			}
			//? ELSE IF tree is RIGHT heavy
			else if (BalanceFactor < -1)
			{
				// std::cout << "Right heavy : ";
				// std::cout << "L " << difference(root->right)  << std::endl<< std::endl;
				if (difference(root->right) > 0)
					root = rightLeftRotation(root); //? Right Left
				else 
					root = rightRightRotation(root); //? Right Right
			}
			return root;
		}
		
		bool			searchForKey(const Key key, node_type* root)
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
		
		//?  Perform Rotation
		node_type*		insert(node_type *root, const Key key, const T value)
		{
			// std::cout << root->data._first << key << std::endl;
			if (root == nullptr)
			{
				root = newNode(key, value);
				std::cout << "Value inserted successfully" << std::endl;
			}
			if (!searchForKey(key, root))
			{
				if (key < root->data._first)
				{
					root->left = insert(root->left, key, value);
					root = balanceTree(root);
				}
				else if (key > root->data._first) //! switch to compare Compare(key, root->data._first)
				{
					root->right = insert(root->right, key, value);
					root = balanceTree(root);
				}
			} //! search if tha key exists or not
			return root;
		}

		node_type*		beginTree(node_type *root)
		{
			node_type *current = root;
			// std::cout << "begin : " <<"{" << current->data._first << "}" << std::endl;
			while (current->left != nullptr)
				current = current->left;
			return current;
		}

		node_type*		minValue(node_type *root)
		{
			node_type *current = root;
			if (current->right != nullptr)
			{
				while (current->right != nullptr)
					current = current->right;
			}
			// std::cout << "minValue : " <<"[" << current->data._first << "]" << std::endl;
			return current;
		}

		node_type*		deleteNode(node_type *root,const Key key)
		{
			if (root == nullptr)
				return nullptr;
			else if (key < root->data._first)
			{
				root->left = deleteNode(root->left, key);
				// std::cout << "Left"  << std::endl;
			}
			else if (key > root->data._first)
			{
				root->right = deleteNode(root->right, key);
				// std::cout << "Right" << std::endl;
			}
			else if (key == root->data._first)	//! delete the root cases (root wit no child, one child, x childs)
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
					node_type *ret = minValue(root->left);
					// std::cout << "ret : "<< ret->data._first << std::endl;
					root->data = ret->data;
					root->left = deleteNode(root->left, ret->data._first);
				}
			}
			return root;		
		}
		
		// private:
			// typename _A::template rebind<_Ty>::other 
			// using nodeAlloc = typename pairAllocator::template rebind<Node>::other;
		public:
			typename pairAllocator::template rebind<Node>::other nodeAlloc;
			node_type	*rootPtr;
			pair_alloc	pairAlloc;
			size_t		treeSize;
	};
}

// https://stackoverflow.com/questions/57206516/how-standard-containers-allocates-memory-for-their-nodes-internal-structures
// https://stackoverflow.com/questions/37284243/why-can-stdlist-have-an-allocator-of-type-t

#endif