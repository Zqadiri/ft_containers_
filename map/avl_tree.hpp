/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/02 13:54:05 by zqadiri          ###   ########.fr       */
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
			typedef		T			value_type;
			typedef		Node		node_type;
			typedef		Alloc		value_alloc;
			typedef		nodeAllocator	node_alloc;

		node_type*		newNode(value_type data)
		{
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			newNode->data= data;
			return newNode;
		}
		
		node_type*		insert(node_type *root, value_type data)
		{
			if (root == nullptr)
				root = newNode(data);
			else if (data <= root->data)
				root->left = insert(root->left, data);
			else
				root->right = insert(root->right, data);
			return root;
		}
	
		private:
			node_alloc	nodeAlloc;
				
	};
}

int main()
{
	
}

#endif