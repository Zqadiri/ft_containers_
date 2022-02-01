/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/02/01 19:37:09 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_
#define AVL_TREE_

#include "../utilities/utility.hpp"
#include <iostream>

namespace ft
{
	template <typename T, class Alloc = std::allocator<ft::BstNode<T> > >
	class avl_tree
	{

		typedef		Alloc	_alloc;
		

		// BstNode* GetNewNode(int data) {
		// 	BstNode* newNode = _alloc.allocate(1);
		// 	newNode->data = data;
		// 	newNode->left = newNode->right = NULL;
		// 	return newNode;
		// }
		
		// BstNode* Insert(BstNode* root,int data) {
		// 	if (root == nullptr)
		// 		root = GetNewNode(data);
		// }
				
	};
}

int main()
{
	
}

#endif