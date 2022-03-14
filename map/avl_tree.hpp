/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/03/08 14:42:21 by zqadiri          ###   ########.fr       */
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
			rootPtr = nodeAlloc.allocate(1);
			rootPtr->right = rootPtr->left = nullptr;
			rootPtr = nullptr;
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

		bool operator!=(const avl_tree &rhs)const {
			return (rootPtr != rhs.rootPtr);
		}

		~avl_tree(){};

		node_type *nextNode(node_type *node)const 
		{
			node_type *temp;
			if (node == nullptr)
			{
				node = rootPtr;
				if (node == nullptr) //! empty tree
					throw std::underflow_error("map : "); //! change it [Occurs when the result is not zero, but is too small to be represented]
				while (node->left != nullptr){
					node = node->left; //* move to the smallest value in the tree
				}
			}
			else if (node->right != nullptr)
			{
				node = node->right; //* successor is the farthest left node of right subtree
				while (node->left != nullptr){
					node = node->left;
				}
			}
			else
			{
				temp = node->rootPtr;
				while (temp != nullptr && node == temp->right){
					node = temp;
					temp = temp->rootPtr;
				}
				node = temp;
			}
			return node;
		}
		
		node_type *preNode(node_type *node)const
		{
			node_type *temp;
			if (node == nullptr)
			{
				node = rootPtr;
				if (node == nullptr)
					throw std::underflow_error("map : ");
				while (node->right != nullptr)
					node = node->right;
			}
			else if (node->left != nullptr)
			{
				node = node->left;
				while (node->right != nullptr)
					node = node->right;
			}
			else
			{
				temp = node->rootPtr;
				while (temp != nullptr && node == temp->left)
				{
					node = temp;
					temp = temp->rootPtr;
				}
				node = temp;
			}
			return node;
		}

		node_type* lowerBound (node_type *first,const key_type& key) const{
			while (first != NULL){
				if (comp(first->data.first, key))
					first = this->nextNode(first);
				else
					break ;
			}
			return first;
		}

		node_type* upperBound (node_type *first,const key_type& key) const{
			while (first != NULL){
				if (!comp(key, first->data.first))
					first = this->nextNode(first);
				else					
					break ;
			}
			return first;
		}

		node_type*		beginTree( node_type *root) const 
		{
			node_type *current = root;
			while (current->left != nullptr)
				current = current->left;
			return current;
		}

		bool		isEmpty(){
			return (rootPtr == nullptr);
		}

		void	updateHeight(node_type* root, node_type* new_parent){
			root->Height = max(height(root->left), height(root->right)) + 1;
			new_parent->Height = max(height(new_parent->left), height(new_parent->right)) + 1;
		}
		
		node_type*		leftLeftCase(node_type *root)
		{
			// std::cout << "root : "  << root->data.first << std::endl;
			node_type *new_parent = root->left;
			node_type *tmp = new_parent->right; 
			new_parent->right = root;
			root->left = tmp;
			if (root->left != nullptr)
				root->left->rootPtr  = new_parent->right;
			new_parent->rootPtr = root->rootPtr;
			root->rootPtr = new_parent;
			updateHeight(root, new_parent);
			// std::cout << "leftLeftCase" << std::endl;
			return new_parent;
		}

		node_type*		rightRightCase(node_type *root)
		{
			node_type *new_parent = root->right;
			node_type *tmp = new_parent->left;
			new_parent->left = root;
			root->right = tmp;
			if (root->right != nullptr)
				root->right->rootPtr  = new_parent->left;
			new_parent->rootPtr = root->rootPtr;
			root->rootPtr = new_parent;
			updateHeight(root, new_parent);
			// std::cout << "RightRightCase" << std::endl;
			return new_parent;
		}

		node_type*		balanceTree(node_type *node, const key_type &key)
		{
  			node->Height = 1 + max(height(node->left), height(node->right));
  			int balanceFactor = getBalanceFactor(node);
			// std::cout << "balanceFactor : " << balanceFactor  << std::endl;
  			if (balanceFactor > 1)
			{
  				if (comp(key, node->left->data.first))
  					return leftLeftCase(node);
  				else if (!comp(key, node->left->data.first))
				{
  				  	node->left = rightRightCase(node->left);
  					return leftLeftCase(node);
  				}
  			}
  			if (balanceFactor < -1)
			{
  				if (!comp(key, node->right->data.first))
  					return rightRightCase(node);
  				else if (comp(key, node->right->data.first))
				{
  					node->right = leftLeftCase(node->right);
  					return rightRightCase(node);
  				}
  			}
			return node;
		}

		node_type		*balanceAfterRemove(node_type *node, const key_type key)
		{
			node->Height = 1 + max(height(node->left), height(node->right));
  			int balanceFactor = getBalanceFactor(node);
			
			// Left Left Case
			if (balanceFactor > 1 &&
				getBalanceFactor(node->left) >= 0)
				return leftLeftCase(node);
		
			// Left Right Case
			if (balanceFactor > 1 &&
				getBalanceFactor(node->left) < 0)
			{
				node->left = rightRightCase(node->left);
				return leftLeftCase(node);
			}
		
			// Right Right Case
			if (balanceFactor < -1 &&
				getBalanceFactor(node->right) <= 0)
				return rightRightCase(node);
		
			// Right Left Case
			if (balanceFactor < -1 &&
				getBalanceFactor(node->right) > 0)
			{
				node->right = leftLeftCase(node->right);
				return rightRightCase(node);
			}
			return node;
		}

		
		bool			searchForKey(const key_type key, node_type* root)const
		{
			if (root == nullptr) // * rearch the end of the tree
				return false;
			else if (root->data.first == key)
				return true;
			else if (!comp(key, root->data.first))
				return searchForKey(key, root->right);
			else
				return searchForKey(key, root->left);
		}

		node_type*		searchKey(const key_type key, node_type* root) const
		{
			if (root == nullptr) // * rearch the end of the tree
				return root;
			else if (root->data.first == key)
				return root;
			else if (!comp(key, root->data.first))
				return searchKey(key, root->right);
			else
				return searchKey(key, root->left);
		}
		
		node_type*		newNode(const value_type &val){
			node_type *newNode = nodeAlloc.allocate(1);
			newNode->right = newNode->left = nullptr;
			nodeAlloc.construct(newNode, ft::make_pair(val.first, val.second));
			newNode->Height = 1;
			treeSize++;
			return newNode;
		}

		int height(node_type *node) {
			if (node == nullptr)
			  return 0;
			return node->Height;
		}

		int getBalanceFactor(node_type *node) {
			if (node == nullptr)
			  return 0;
			return height(node->left) - height(node->right);
		}

		node_type* insert(node_type *node, const value_type &val)
		{
			if (node == nullptr){
				node = newNode(val);
				node->rootPtr = nullptr;
				return (node);
			}
			else if (!searchForKey(val.first, node))
			{
				if (comp(val.first, node->data.first))
				{
					node_type *lchild = insert(node->left, val);
					node->left = lchild;
					lchild->rootPtr = node;
				}
				else if (!comp(val.first, node->data.first))
				{
					node_type *rchild = insert(node->right, val);
					node->right  = rchild;
					rchild->rootPtr = node;
				}
			}
			node = balanceTree(node, val.first);
			return node;
		}

		node_type*		minValue(node_type *root) const
		{
			node_type *current = root;
			while (current->right != nullptr)
				current = current->right;
			return current;
		}


		node_type*		deleteNode(node_type *root,const key_type key)
		{
			// std::cout << "KeyToRemove : " << key << std::endl; 
			if (root == nullptr)
				return nullptr;
			else if (!comp(key,root->data.first) && (key != root->data.first))
				root->right = deleteNode(root->right, key);
			else if (comp(key,root->data.first))
				root->left = deleteNode(root->left, key);
			else if (key == root->data.first)
			{
				if (root->left == nullptr)
				{
					node_type *new_parent = root->right;
					nodeAlloc.destroy(root);
					if (new_parent != nullptr)
						new_parent->rootPtr = root->rootPtr;
					return new_parent;
				}
				else if (root->right == nullptr )
				{
					node_type *new_parent = root->left;
					nodeAlloc.destroy(root);
					if (new_parent != nullptr)
						new_parent->rootPtr = root->rootPtr;
					return new_parent;
				}
				else{
					node_type *ret = minValue(root->left);
					nodeAlloc.destroy(root);
					nodeAlloc.construct(root, ft::make_pair(ret->data.first, ret->data.second));
					root->left = deleteNode(root->left, ret->data.first);
				}
			}
			root = balanceAfterRemove(root, key);
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