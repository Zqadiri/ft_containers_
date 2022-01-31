/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/01/31 11:57:32 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_
#define AVL_TREE_

#include <iostream>

namespace ft
{
	class avl_tree
	{
		private:
			struct node
			{
				struct node *root; 
				struct node *right;
				struct node *left;
				int height;
				int data;
			};
	
		public:

			avl_tree(){
			}
	
			/*
			TODO:Left Rotation
			** This rotation is performed when a new node is 
			** inserted at the left child of the left subtree.
			*/
			
			struct node *llRotation(struct node *node)
			{
				
				return (node);
			}
	};
}

#endif