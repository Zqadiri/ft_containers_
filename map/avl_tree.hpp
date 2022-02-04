/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/04 18:05:21 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_
#define AVL_TREE_

#include "../utilities/utility.hpp"
#include <iostream>

namespace ft
{
	
	template <typename T, typename Node = ft::BstNode<T>, typename Alloc = std::allocator<T>,
	 typename nodeAllocator = std::allocator<ft::BstNode<T> > >
	class avl_tree
	{
		public:
			typedef		T				value_type; //! pair
			typedef		Node			node_type;
			typedef		Alloc			value_alloc;
			typedef		nodeAllocator	node_alloc;

		node_type*		newNode(value_type data)
		{
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			newNode->data= data;
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
		node_type*		insert(node_type *root, value_type data)
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
			while (current->left != nullptr){
				current = current->left;
			}
			return current;
		}

		node_type*		deleteNode(node_type *root, value_type data)
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
			else if (data == root->data) //! delete the root cases (root wit no child, one child, x childs)
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
					node_type *ret = minValue(root);
					std::cout << "ret : "<< ret->data << std::endl;
					//? x childs
				}
			}
			return root;		
		}
		

		private:
			node_alloc	nodeAlloc;
			value_alloc	valueAlloc;
				
	};
}

#endif