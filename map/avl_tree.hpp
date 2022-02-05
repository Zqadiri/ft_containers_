/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/05 16:23:38 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_
#define AVL_TREE_

#include "../utilities/utility.hpp"
#include <iostream>
#include <sys/types.h>
namespace ft
{
	
	template <typename Key, typename T, typename Node = ft::BstNode<Key, T>, typename nodeAllocator = std::allocator<Node>,
	 typename pairAllocator = std::allocator<ft::pair<const Key, T> > >
	class avl_tree
	{
		public:
			typedef		Key					key_type; //? key_t defined in types.h https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/shm/key.html#:~:text=Unix%20requires%20a%20key%20of,a%20key%20is%20system%20dependent.
			typedef		T 					mapped_type;
			typedef		Node				node_type;
			typedef		pairAllocator		pair_alloc;
			typedef		nodeAllocator		node_alloc;

		node_type*		newNode(mapped_type data)
		{
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			// newNode->data = pairAlloc.allocate(1);
			
			// newNode->data.construct(ft::make_pair(key_type, mapped_type));
			// ft::make_pair(key_type, mapped_type);
			newNode->data = pairAlloc.allocate(ft::make_pair(key, mapped));
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
			// puts("in");
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
		
		//?  Perform Rotation
		node_type*		insert(node_type *root, mapped_type data)
		{
			if (root == nullptr)
				root = newNode(data);
			else if (data < root->data)
			{
				root->left = insert(root->left, data);
				root = balanceTree(root);
			}
			else if (data > root->data)
			{
				root->right = insert(root->right, data);
				root = balanceTree(root);
			}
			return root;
		}

		node_type*		minValue(node_type *root)
		{
			node_type *current = root;
			while (current->right != nullptr){
				current = current->right;
			}
			return current;
		}

		node_type*		deleteNode(node_type *root, mapped_type data)
		{
			if (root == nullptr)
				return nullptr;
			else if (data < root->data)
			{
				root->left = deleteNode(root->left, data);
				std::cout << "Left"  << std::endl;
			}
			else if (data > root->data)
			{
				root->right = deleteNode(root->right, data);
				std::cout << "Right"  << std::endl;
			}
			else if (data == root->data)	//! delete the root cases (root wit no child, one child, x childs)
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
					//? x childs
					node_type *ret = minValue(root->left);
					std::cout << "ret : "<< ret->data << std::endl;
					root->data = ret->data;
					root->left = deleteNode(root->left, ret->data);
				}
			}
			return root;		
		}
		

		private:
			node_alloc	nodeAlloc;
			pair_alloc	pairAlloc;
			key_type	key;
			mapped_type	mapped;
				
	};
}

#endif